#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage : %s\n",strerror(errno));
    exit(1);
  }
  if (access(argv[1],R_OK) == 0) {
    printf("%s 该文件可读\n",argv[1] );
  }else{
    printf("%s 该文件不可读\n",argv[1] );
  }
  return 0;
}
