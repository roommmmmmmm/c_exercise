#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage : %s\n",strerror(errno));
    exit(1);
  }
  struct stat buf;
  //stat只会获取到源文件，不会获取软连接文件
  // if (stat(argv[1],&buf) < 0) {
  // lstat可以判断一个文件是否是符号链接文件
  if (lstat(argv[1],&buf) < 0) {
    fprintf(stderr, "stat failed %s\n", strerror(errno));
    exit(1);
  }
  mode_t mode = buf.st_mode;

  if (S_ISREG(mode)) {
    printf("%s 是普通文件\n", argv[1]);
  }
  if (S_ISDIR(mode)) {
    printf("%s 是目录文件\n", argv[1]);
  }
  if (S_ISBLK(mode)) {
    printf("%s 是块特殊文件\n", argv[1]);
  }
  if (S_ISCHR(mode)) {
    printf("%s 是字符特殊文件\n", argv[1]);
  }
  if (S_ISSOCK(mode)) {
    printf("%s 是套接字文件\n", argv[1]);
  }
  if (S_ISLNK(mode)) {
    printf("%s 是符号链接文件\n", argv[1]);
  }

  return 0;
}
