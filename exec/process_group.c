#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  pid_t pid;
  pid_t group1;
  pid_t group2;
  int i ;
  setpgid(getpid(),getpid());
  group1 = getpgid(getpid());
  for ( i = 0; i < 3; i++) {
    pid = fork();
    switch (pid) {
      case -1:
      fprintf(stderr, "vfork error :%s\n", strerror(errno));
      exit(1);
      break;
      case 0:
        if (i == 0) {
          setpgid(getpid(),group1);
        }
        if (i == 1) {
          setpgid(getpid(),getpid());
          group2 = getpgid(getpid());
        }
        if (i == 2) {
          setpgid(getpid(),group2);
        }
        break;
      default:
          if (i == 0) {
            setpgid(pid,group1);
          }
          if (i == 1) {
            setpgid(pid,pid);
            group2 = getpgid(pid);
          }
          if (i == 2) {
            setpgid(pid,group2);
          }
          break;
    }
    //
    // if(pid < 0)
    // {
    //     fprintf(stderr,"fork error:%s\n",strerror(errno));
    //     exit(1);
    // }
    // else if(pid > 0) //parent process
    // {
    //     if (i == 0)
    //     {
    //         setpgid(pid,group1);
    //     }
    //     if (i == 1)
    //     {
    //         setpgid(pid,pid);
    //         group2 = getpgid(pid);
    //     }
    //     if (i == 2)
    //     {
    //         setpgid(pid,group2);
    //     }
    // }else           //child process
    // {
    //     if(i == 0)
    //     {
    //         setpgid(getpid(),group1);
    //     }
    //
    //     if(i == 1)
    //     {
    //         setpgid(getpid(),getpid());
    //         group2 = getpgid(getpid());
    //     }
    //     if(i == 2)
    //     {
    //         setpgid(getpid(),group2);
    //     }
    //     break;
    // }
  }
  printf("pid : %d,ppid : %d,groupid : %d\n",getpid(),getppid(),getpgid(0));
  sleep(20);
  return 0;
}
