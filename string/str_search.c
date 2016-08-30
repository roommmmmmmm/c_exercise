#include <stdio.h>
#include <stdlib.h>

//查找字符串中各个字符出现的次数

void FindTimes(char *str) {
  int hash[256] = {0};
  int index = 0;
  while (str[index] != '\0') {
    hash[str[index]]++;
    index++;
  }
  for ( index = 0; index < 256 ; index++) {
    printf("%d\n",hash[index] );
  }
}
int main(int argc, char const *argv[]) {
  char str[] = "my name is xiaozhuang";
  FindTimes(str);
  return 0;
}
