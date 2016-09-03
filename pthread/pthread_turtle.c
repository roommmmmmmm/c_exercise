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
  for ( i = s; i < e; i++) {
    printf("pthread_t : %ld,i = %d\n",pthread_self(),i);
    double r = drand48();
    int rt = (int)(r*100000);
    usleep(rt);
  }
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
  pth_arg arg2 = {50,100};
  if ((err=pthread_create(&pth2,NULL,th_fun,(void*)&arg2)) != 0) {
    fprintf(stderr, "pthread_create : %s\n", strerror(err));
    exit(1);
  }
  sleep(10);
  printf("finish\n");
  return 0;
}
