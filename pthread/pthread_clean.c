#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>


void clean_fun(void *arg) {
  printf("clean arg : %s\n",(char *)arg );
}


//线程执行函数
void *th_fun(void *arg) {
  printf("id : %ld\n",pthread_self());
  int execute = (int)arg;
  pthread_cleanup_push(clean_fun,"hello,world");
  pthread_cleanup_push(clean_fun,"hello,xiaozhuang");
  pthread_cleanup_pop(execute);
  pthread_cleanup_pop(execute);
}


int main(int argc, char const *argv[]) {
  pthread_t pth1;
  pthread_t pth2;
  int err;
  if ((err = pthread_create(&pth1,NULL,th_fun,(void*)0)) != 0) {
    fprintf(stderr, "pthread_create : %s\n",strerror(err));
  }
  pthread_join(pth1,NULL);
  printf("--------------------------\n");
  if ((err = pthread_create(&pth2,NULL,th_fun,(void*)2)) != 0) {
    fprintf(stderr, "pthread_create : %s\n",strerror(err));
  }
  pthread_join(pth2,NULL);
  return 0;
}
