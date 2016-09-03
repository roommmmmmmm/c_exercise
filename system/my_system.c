#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void my_system(char *cmd) {
  pid_t pid;
  pid = vfork();
  switch (pid) {
    case -1:
      fprintf(stderr, "vfork error :%s\n", strerror(errno));
      exit(1);
    case 0 :
      execl("/bin/bash","bash","-c",cmd,NULL);
      break;
    default:
      wait(0);
      break;
  }
}
int main(int argc, char const *argv[]) {
  my_system("cat /etc/passwd");
  printf("-------------------------\n");
  my_system("cat /etc/passwd | grep root");
  return 0;
}
