#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[] ,char *envp[]) {
  pid_t pid;
  int stat_val;
  printf("Exec example!\n");
  pid = fork();
  switch (pid) {
    case -1:
      perror("Process Creation Failed \n");
      exit(1);
    case 0 :
      printf("Child process is running\n");
      printf("My pid = %d ,parentpid = %d\n",getpid(),getppid());
      printf("uid = %d,gid = %d\n",getuid(),getgid());
      execve("processimage",argv,envp);
      printf("process never go to here!\n");
      exit(0);
    default :
      printf("Parent process is running\n");
      break;
  }
  wait(&stat_val);
  return 0;
}
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
