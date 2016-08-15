#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char const *argv[]) {

  int fd;
  fd = open (argv[1], O_CREAT | O_EXCL , S_IRUSR | S_IWUSR );
  if (-1 == fd) {
    printf("open:%s   with  errno : %d\n",strerror(errno),errno );
    exit(1);
  }else{
    printf("Create file success!\n");
  }
  close(fd);
  return 0;
}
