#include <stdio.h>
#include <malloc.h>

int main(int argc, char const *argv[], char **envp) {
  int i;
  for (i = 0; *envp != NULL;i++) {
    printf("%s\n", *envp++);
  }
  return 0;
}
