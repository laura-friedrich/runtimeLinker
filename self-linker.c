//self-linker.c

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

extern void *_GLOBAL_OFFSET_TABLE_;

int main (int argc, char *argv[]){

  puts("hello");

  void *handle;
  void *putsSym;
  handle= dlopen("/usr/lib/libc.so.6", RTLD_LAZY);
  putsSym= dlsym(handle, "puts");
  printf("putsSym is %p\n" , putsSym);
  printf("putsSym is %p\n" , &putsSym);

  //(char *) &_GLOBAL_OFFSET_TABLE_ + 2 = putsSym;


  printf("My _GLOBAL_OFFSET_TABLE_ is %p\n" , _GLOBAL_OFFSET_TABLE_);
  printf("This is located at %p\n", &_GLOBAL_OFFSET_TABLE_);

  printf("The next element is %p\n", _GLOBAL_OFFSET_TABLE_ +1);
  printf("This next element is located at %p\n", &_GLOBAL_OFFSET_TABLE_+1);

  puts("hello");
  puts("world");

  dlclose(handle);

  return 0;
}
