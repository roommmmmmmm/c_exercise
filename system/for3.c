#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
//此程序演示了孤儿进程

int main(int argc, char const *argv[]) {
  pid_t pid;

  pid = fork();

  int i;
  switch (pid) {
    case 0 :
    //子进程在输出消息后，延时。
      for ( i = 0; i < 10; i++) {
        printf("A background process, PID : %d,Parentid : %d\n",getpid(),getppid() );
        sleep(3);
      }
    case -1:
      perror("Process Creation Failed \n");
      exit(-1);
    default://父进程输出信息后，直接自杀
      printf("I am parent Process,my pid is %d\n",getpid() );
      exit(0);
  }
  return 0;
}
