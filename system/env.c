#include <stdio.h>
#include <malloc.h>

extern char **environ;

int main(int argc, char const *argv[]) {
  int i;

  printf("Environment : \n");
  for (i = 0; environ[i] !=NULL; i++) {
    printf("%s\n",environ[i]);
  }
  return 0;
}
