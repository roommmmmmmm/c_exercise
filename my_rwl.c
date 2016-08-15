#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
//定义错误处理函数
void my_err(const char *err_string, int line);
// 定义读数据函数
int my_read(int fd);


int main() {
  int fd;
  char write_buf[32] = "Hello,World!";
  //创建一个文件
  if ((fd = open("test_file.c",O_RDWR|O_CREAT|TRUNC,S_IRWXU)) == -1) {
    my_err("open",_LINE_);
  }else{
    printf("Create file success !\n" );
  }
  //写数据
  if (write(fd,write_buf,strlen(write_buf)) != strlen(write_buf)) {
    my_err("write",_LINE_);
  }
  my_read(fd);

  printf("/*-------------------------------*/\n" );
  if (lseek(fd,10,SEEK_END) == -1) {
    my_err("lseek",_LINE_);
  }
  if (write(fd,write_buf,strlen(write_buf)) != strlen(write_buf)) {
    my_err("write",_LINE_);
  }

  my_read(fd);
  close(fd);
  return 0;
}

void my_err(const char *err_string, int line) {
  fprintf(stderr, "line : $d", line);
  perror(err_string);
  exit(1);
}

int my_read(int fd){
  int len;
  int ret;
  int i ;
  char read_buf[64];
  //获取文件长度并保持文件读写指针在文件开始处
  if (lseek(fd,0,SEEK_END) == -1) {
    my_err("lseek",_LINE_);
  }
  if ((len = lseek(fd,0,SEEK_CUR)) == -1) {
    my_err("lseek",_LINE_);
  }
  if ((lseek(fd,0,SEEK_SET)) == -1) {
    my_err("lseek",_LINE_);
  }
  printf("len : %d\n", len);
  //读数据
  if ((ret = read(fd,read_buf,len)) < 0) {
    my_err("read",_LINE_);
  }
  //打印数据
  for ( i = 0; i < len; i++) {
    printf("%c\n",read_buf[i] );
  }
  printf("\n");
  return ret;
}
