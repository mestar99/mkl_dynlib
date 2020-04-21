
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char * argv[])
{
  if(argc != 2) {
    printf("Usage: %s <shared object>\n",argv[0]);

    return 1;
  }

  int flags;

#ifndef LOAD_GLOBAL
  flags = RTLD_LOCAL; // not working
#else
  flags = RTLD_GLOBAL; // working
#endif

  void * libhandle = dlopen( argv[1], RTLD_LAZY | flags);

  if( libhandle == NULL ) {
    printf("Error opening dynamic lib - %s\n", argv[1]);

    char * err = dlerror();
    printf("%s\n",err);

    return 1;
  }

  void (*some_mkl_wrapper)();

  some_mkl_wrapper = (void (*)()) dlsym( libhandle, "this_mkl_wrapper" );

  (*some_mkl_wrapper)();

  if( dlclose(libhandle) != 0 ) {
    printf("Error closing dynamic lib\n");
  }

  return 0;
}
