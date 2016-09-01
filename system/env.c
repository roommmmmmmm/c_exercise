#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

extern char **environ;

int main(int argc, char const *argv[]) {
  int i;

  printf("Environment : \n");
  for (i = 0; environ[i] !=NULL; i++) {
    printf("%s\n",environ[i]);
  }
  printf("--------------------------\n");
  printf("PATH:%s\n",getenv("PATH"));
  setenv("PATH","..:/bin/usr/bin",1);
  printf("PATH:%s\n",getenv("PATH"));
  putenv("NAME=xiaozhuang");
  printf("NAME:%s\n",getenv("NAME"));
  return 0;
}
