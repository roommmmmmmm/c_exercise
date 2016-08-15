#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
//此程序演示了fork函数创建进程时返回值的不同
int main(void) {
  pid_t pid;
  printf("Process Creation Study\n");
  pid = fork();
  switch (pid) {
    case 0 :
    //获得父进程的id
      printf("Child Process is running ,CurPid is %d ,ParentPid is %d\n", pid,getppid());
      break;
    case -1 :
      perror("Process Creation Failed\n" );
      break;
    default:
    //获得进程id
      printf("Parent Process is running,ChildPid Process is %d,PartentPid is %d\n",pid,getpid() );
      break;
  }
  exit(0);
}
