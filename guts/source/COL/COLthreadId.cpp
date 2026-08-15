#include "COLthreadId.h"
#include <pthread.h>

COLuint64 COLthreadId(){
   return (COLuint64)pthread_self();
}




