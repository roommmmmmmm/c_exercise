#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>

int sockfd;

int main(int argc, char const *argv[]) {

  if (argc < 3) {
    fprintf(stderr, "usage : %s\n", argv[0]);
    exit(1);
  }

  //create socket
  sockfd = socket(AF_INET,SOCK_STREAM,0);
  if (sockfd < 0) {
    fprintf(stderr, "socket : %s\n", strerror(errno));
    exit(1);
  }

  //set ip and port
  struct sockaddr_in addr;
  memset(&addr,0,sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[2]));//把本地字节序转换成网络字节序
  inet_pton(AF_INET,argv[1],&addr.sin_addr.s_addr);
  socklen_t len = sizeof(addr);

  if (connect(sockfd,(struct sockaddr*)&addr,len) < 0) {
    fprintf(stderr, "connect : %s\n", strerror(errno));
    exit(1);
  }
  char buffer[1024];
  memset(buffer,0,sizeof(buffer));
  ssize_t n;
  n = read(sockfd,buffer,1024);
  if ( n < 0 ) {
    fprintf(stderr, "read : %s\n", strerror(errno));
    exit(1);
  }else{
    printf("%s\n", buffer);
  }
  return 0;
}
