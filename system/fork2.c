#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
//此程序演示了，父子进程交替执行
int main(void) {
  pid_t pid;
  char *msg;
  int k;
  printf("Process Creation Study\n");
  pid = fork();
  switch (pid) {
    case 0 :
    //子进程
      msg = "Child Process is running";
      k = 3;
      break;
    case -1 :
      perror("Process Creation Failed\n" );
      break;
    default:
    //父进程
      msg = "Parent Process is running";
      k = 5;
      break;
  }
  while (k > 0) {
    puts(msg);
    sleep(2);
    k--;
  }
  exit(0);
}
