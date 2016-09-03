#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage : %s\n",strerror(errno));
    exit(1);
  }
  struct stat st;
  stat(argv[1],&st);
  mode_t mode = st.st_mode;
  //所有者权限
  if (mode & S_IRUSR) {
    printf("r");
  }else{
    printf("-" );
  }
  if (mode & S_IWUSR) {
    printf("w");
  }else{
    printf("-" );
  }
  if (mode & S_IXUSR) {
    printf("x");
  }else{
    printf("-" );
  }
  //所属组权限
  if (mode & S_IRGRP) {
    printf("r");
  }else{
    printf("-" );
  }
  if (mode & S_IWGRP) {
    printf("w");
  }else{
    printf("-" );
  }
  if (mode & S_IXGRP) {
    printf("x");
  }else{
    printf("-" );
  }
  //其他人访问权限
  if (mode & S_IROTH) {
    printf("r");
  }else{
    printf("-" );
  }
  if (mode & S_IWOTH) {
    printf("w");
  }else{
    printf("-" );
  }
  if (mode & S_IXOTH) {
    printf("x");
  }else{
    printf("-" );
  }
  return 0;
}
