/*
** $Id: lstate.c,v 1.123 2003/04/03 13:35:34 roberto Exp $
** Global State
** See Copyright Notice in lua.h
*/


#include "stdlib.h"

#define lstate_c

#include "LUAClua.h"

#include "LUACdebug.h"
#include "LUACdebugApi.h"
#include "LUACdo.h"
#include "LUACfunc.h"
#include "LUACgc.h"
#include "LUAClex.h"
#include "LUACmem.h"
#include "LUACstate.h"
#include "LUACstring.h"
#include "LUACtable.h"
#include "LUACtm.h"


/*
** macro to allow the inclusion of user information in Lua state
*/
#ifndef LUA_USERSTATE
#define EXTRASPACE	0
#else
union UEXTRASPACE {L_Umaxalign a; LUA_USERSTATE b;};
#define EXTRASPACE (sizeof(union UEXTRASPACE))
#endif



/*
** you can change this function through the official API:
** call `lua_setpanicf'
*/
static int default_panic (lua_State *L) {
  UNUSED(L);
  return 0;
}


static lua_State *mallocstate (lua_State *L) {
  lu_byte *block = (lu_byte *)luaM_malloc(L, sizeof(lua_State) + EXTRASPACE);
  if (block == COLnull) return COLnull;
  else {
    block += EXTRASPACE;
    return cast(lua_State *, block);
  }
}


static void freestate (lua_State *L, lua_State *L1) {
  luaM_free(L, cast(lu_byte *, L1) - EXTRASPACE,
               sizeof(lua_State) + EXTRASPACE);
}


static void stack_init (lua_State *L1, lua_State *L) {
  L1->stack = luaM_newvector(L, BASIC_STACK_SIZE + EXTRA_STACK, TObject);
  L1->stacksize = BASIC_STACK_SIZE + EXTRA_STACK;
  L1->top = L1->stack;
  L1->stack_last = L1->stack+(L1->stacksize - EXTRA_STACK)-1;
  L1->base_ci = luaM_newvector(L, BASIC_CI_SIZE, CallInfo);
  L1->ci = L1->base_ci;
  L1->ci->state = CI_C;  /*  not a Lua function */
  setnilvalue(L1->top++);  /* `function' entry for this `ci' */
  L1->base = L1->ci->base = L1->top;
  L1->ci->top = L1->top + LUA_MINSTACK;
  L1->size_ci = BASIC_CI_SIZE;
  L1->end_ci = L1->base_ci + L1->size_ci;
}


static void freestack (lua_State *L, lua_State *L1) {
  luaM_freearray(L, L1->base_ci, L1->size_ci, CallInfo);
  luaM_freearray(L, L1->stack, L1->stacksize, TObject);
}


/*
** open parts that may cause memory-allocation errors
*/
static void f_luaopen (lua_State *L, void *ud) {
  /* create a new global state */
  global_State *g = luaM_new(COLnull, global_State);
  UNUSED(ud);
  if (g == COLnull) luaD_throw(L, LUA_ERRMEM);
  L->l_G = g;
  g->mainthread = L;
  g->GCthreshold = 0;  /* mark it as unfinished state */
  g->strt.size = 0;
  g->strt.nuse = 0;
  g->strt.hash = COLnull;
  setnilvalue(defaultmeta(L));
  setnilvalue(registry(L));
  setnilvalue(stringmeta(L));
  luaZ_initbuffer(L, &g->buff);
  g->panic = default_panic;
  g->rootgc = COLnull;
  g->rootudata = COLnull;
  g->tmudata = COLnull;
  setnilvalue(gkey(g->dummynode));
  setnilvalue(gval(g->dummynode));
  g->dummynode->next = COLnull;
  g->nblocks = sizeof(lua_State) + sizeof(global_State);
  stack_init(L, L);  /* init stack */
  /* create default meta table with a dummy table, and then close the loop */
  defaultmeta(L)->tt = LUA_TTABLE;
  sethvalue(defaultmeta(L), luaH_new(L, 0, 0));
  hvalue(defaultmeta(L))->metatable = hvalue(defaultmeta(L));
  sethvalue(gt(L), luaH_new(L, 0, 4));  /* table of globals */
  sethvalue(registry(L), luaH_new(L, 4, 4));  /* registry */
  luaS_resize(L, MINSTRTABSIZE);  /* initial size of string table */
  luaT_init(L);
  luaX_init(L);
  luaS_fix(luaS_newliteral(L, MEMERRMSG));
  g->GCthreshold = 4*G(L)->nblocks;
}


static void preinit_state (lua_State *L) {
  L->stack = COLnull;
  L->stacksize = 0;
  L->errorJmp = COLnull;
  L->hook = COLnull;
  L->hookmask = L->hookinit = 0;
  L->basehookcount = 0;
  L->allowhook = 1;
  resethookcount(L);
  L->openupval = COLnull;
  L->size_ci = 0;
  L->nCcalls = 0;
  L->base_ci = L->ci = COLnull;
  L->errfunc = 0;
  setnilvalue(gt(L));
}


static void close_state (lua_State *L) {
  luaF_close(L, L->stack);  /* close all upvalues for this thread */
  if (G(L)) {  /* close global state */
    luaC_sweep(L, 1);  /* collect all elements */
    lua_assert(G(L)->rootgc == COLnull);
    lua_assert(G(L)->rootudata == COLnull);
    luaS_freeall(L);
    luaZ_freebuffer(L, &G(L)->buff);
  }
  freestack(L, L);
  if (G(L)) {
    lua_assert(G(L)->nblocks == sizeof(lua_State) + sizeof(global_State));
    luaM_freelem(COLnull, G(L));
  }
  freestate(COLnull, L);
}


lua_State *luaE_newthread (lua_State *L) {
  lua_State *L1 = mallocstate(L);
  luaC_link(L, valtogco(L1), LUA_TTHREAD);
  preinit_state(L1);
  L1->l_G = L->l_G;
  stack_init(L1, L);  /* init stack */
  setobj2n(gt(L1), gt(L));  /* share table of globals */
  return L1;
}


void luaE_freethread (lua_State *L, lua_State *L1) {
  luaF_close(L1, L1->stack);  /* close all upvalues for this thread */
  lua_assert(L1->openupval == COLnull);
  freestack(L, L1);
  freestate(L, L1);
}


LUA_API lua_State *lua_open (void) {
  lua_State *L = mallocstate(COLnull);
  if (L) {  /* allocation OK? */
    L->tt = LUA_TTHREAD;
    L->marked = 0;
    L->next = L->gclist = COLnull;
    preinit_state(L);
    L->l_G = COLnull;
    if (luaD_rawrunprotected(L, f_luaopen, COLnull) != 0) {
      /* memory allocation error: free partial state */
      close_state(L);
      L = COLnull;
    }
  }
  lua_userstateopen(L);
  return L;
}


static void callallgcTM (lua_State *L, void *ud) {
  UNUSED(ud);
  luaC_callGCTM(L);  /* call GC metamethods for all udata */
}


LUA_API void lua_close (lua_State *L) {
  lua_lock(L);
  L = G(L)->mainthread;  /* only the main thread can be closed */
  luaF_close(L, L->stack);  /* close all upvalues for this thread */
  luaC_separateudata(L);  /* separate udata that have GC metamethods */
  L->errfunc = 0;  /* no error function during GC metamethods */
  do {  /* repeat until no more errors */
    L->ci = L->base_ci;
    L->base = L->top = L->ci->base;
    L->nCcalls = 0;
  } while (luaD_rawrunprotected(L, callallgcTM, COLnull) != 0);
  lua_assert(G(L)->tmudata == COLnull);
  close_state(L);
}
