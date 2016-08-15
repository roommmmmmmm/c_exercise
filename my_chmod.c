#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
  int mode;   // 权限
  int mode_u; // 所有者权限
  int mode_g; // 所属组权限
  int mode_o; // 其他用户权限

  // 检查参数的合法性
  if (3 > argc) {
    printf("%s<mode num> <target file>\n",argv[0]);
    exit(0);
  }

  // 获得命令行参数
  mdoe = atoi(argv[1]);
  if (mode > 777 || mode < 0) {
    printf("mode num Error!\n");
    exit(0);
  }

  mode_u = mode / 100; //计算得到所有者权限
  mode_g = (mode - (mode_u*100)) / 10; //计算得到用户组权限
  mode_o = mode - (mode_u*100) - (mode_g*10); //计算得到其他用户权限
  mode = (mode_u * 8 * 8) + (mode_g * 8) + mode_o; // 进行八进制转换
  path = argv[2];

  if ( -1 == chmod(path,mode) ) {
    perror("chmod error!");
    exit(1);
  }
  return 0;
}
