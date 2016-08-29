#include <stdio.h>
#include <stdlib.h>

/**
 * 递归方式调用字符串的长度
 */
int RecurLength(char *str){
  if (str[0] == '\0') {
    return 0;
  }else{
    return RecurLength(str+1)+1;
  }
}

int main(int argc, char const *argv[]) {
  char str[] = "hello,world";
  printf("str length is %d\n",RecurLength(str));
  return 0;
}
