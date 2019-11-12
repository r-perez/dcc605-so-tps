#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <unistd.h>

int main(int argc, char *argv[])
{
  // main de exemplo
  printf("argc = %d\n", argc);
  int ndx;
  for(ndx = 0; ndx != argc; ++ndx)
      printf("argv[%d] --> %s\n", ndx,argv[ndx]);
  printf("argv[argc] = %p\n", (void*)argv[argc]);
  return 0;
}
