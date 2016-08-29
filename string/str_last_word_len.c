#include <stdio.h>
#include <stdlib.h>

/**
 * 字符串中最后一个单词的长度
 */
int LastWordLength(char *str ,int len){
  //知道字符串长度
  int lastlen = 0;
  int index = len -1;
  while (index >= 0 && str[index--] != ' ') {
    lastlen++;
  }
  return lastlen;
}
//不知道字符串的长度
int LastWordLen(char * str){
  int lastlen = 0;
  int index = 0;
  while (str[index] != '\0') {
    if (str[index] == ' ') {
      lastlen = 0;
    }else{
      lastlen++;
    }
    index++;
  }
  return lastlen;
}
int main(int argc, char const *argv[]) {
  char str[] = "hello world";
  printf("last word length is %d\n",LastWordLength(str,11));
  printf("last word length is %d\n",LastWordLen(str));
  return 0;
}
