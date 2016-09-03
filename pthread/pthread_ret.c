#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct pth_arg{
  int start;
  int end;
} pth_arg;

void *th_fun(void *arg) {
  pth_arg *pa = (pth_arg*)arg;
  int s = pa->start;
  int e = pa->end;
  int i;
  int sum = 0;
  for ( i = s; i <= e; i++) {
    sum +=i;
  }
  // return (void*)sum;
  pthread_exit((void*)sum);
}

int main(int argc, char const *argv[]) {
  pthread_t pth1;
  pthread_t pth2;
  int err;
  pth_arg arg1 = {1,100};
  if ((err=pthread_create(&pth1,NULL,th_fun,(void*)&arg1)) != 0) {
    fprintf(stderr, "pthread_create : %s\n", strerror(err));
    exit(1);
  }
  int *ret;
  pthread_join(pth1,(void**)&ret); //获得线程的返回信息
  printf("sum : %d\n",(int)ret);
  printf("finish\n");
  return 0;
}
