//-------------------------------------------------------
// Copyright (C) 2021 Eliot Muir.  All Rights Reserved
//
// COLerror
// 
// Implementation
//-------------------------------------------------------

#include "COLerror.h"
#include "COLstring.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#include "errno.h"
#include "stdlib.h"
#include "string.h"

COLstring COLerrorMessage(int ErrorCode){
   COL_FUNCTION(COLerrorMessage);

   char Buffer[256];
   strerror_r(ErrorCode, Buffer, sizeof(Buffer));

   COLstring Result = Buffer;
   COL_VAR2(ErrorCode, Result);
   return Result;
}

