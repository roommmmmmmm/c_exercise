#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
/**
 * 获取stat里面的文件属性
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, char const *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage : %s\n",strerror(errno) );
  }
  struct stat buf;
  if (stat(argv[1],&buf) < 0) {
    fprintf(stderr, "stat failed :  %s\n",strerror(errno) );
    exit(1);
  }
  printf("%s length : %ld\n",argv[1],buf.st_size);
  return 0;
}
