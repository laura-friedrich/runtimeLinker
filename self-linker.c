//self-linker.c

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

extern void *_GLOBAL_OFFSET_TABLE_;

int main (int argc, char *argv[]){

  void *handle;
  void *putsSym;
  handle= dlopen("/usr/lib/libc.so.6", RTLD_NOW); //Open lib where puts is located
  if (!handle) {
    fprintf(stderr, "%s\n", dlerror());
    exit(EXIT_FAILURE);
  }

  putsSym= dlsym(handle, "puts"); //a pointer to where puts is located in memory

  if (!putsSym) {
    fprintf(stderr, "%s\n", dlerror());
    exit(EXIT_FAILURE);
  }

  void **addressOfPutsInGOT = &_GLOBAL_OFFSET_TABLE_+3; //a pointer to where puts is in GOT
  *addressOfPutsInGOT= putsSym; //placing the pointer to puts in the GOT

  puts("hello");  //Calling puts
  puts("world");

  if (dlclose(handle) != 0) {
    fprintf(stderr, "%s\n", dlerror());
    exit(EXIT_FAILURE);
  }
  return 0;
}
