#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *th_fun(void *arg) {
  int n  = (int)arg;
  int i;
  for ( i = 1; i < n; i++) {
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
  if ((err=pthread_create(&pth1,NULL,th_fun,(void*)100)) != 0) {
    fprintf(stderr, "pthread_create : %s\n", strerror(err));
    exit(1);
  }
  if ((err=pthread_create(&pth2,NULL,th_fun,(void*)100)) != 0) {
    fprintf(stderr, "pthread_create : %s\n", strerror(err));
    exit(1);
  }
  sleep(10);
  printf("finish\n");
  return 0;
}
