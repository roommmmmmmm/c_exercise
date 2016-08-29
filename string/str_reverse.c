#include <stdio.h>
#include <stdlib.h>

//翻转一个句子，将整个句子以单词为单位进行翻转
/**
 * 1.以字节为单位翻转
 * 2.以单词为单位进行二次翻转
 */
/**
 * 将字符串以字节为单位翻转
 * @param str   [被翻转的字符串]
 * @param begin [字符串的开始位置]
 * @param end   [字符串的结束位置]
 */
void Reverse(char *str,int begin,int end) {
  char tmp;
  while (begin < end) {
    tmp = str[begin];
    str[begin] = str[end];
    str[end] = tmp;
    begin++;
    end++;
  }
}
/**
 * 字符串内部单词翻转，从头部开始，没确定一个单词就进行翻转
 * @param str [被翻转的字符串]
 * @param len [字符串长度]
 */
void Reverse_second(char *str,int len ) {
  int begin,i,j;
  for ( i = 0; i < len;) {
    begin = i;
    for ( j = i; j < len; j++) {
      if (str[j] == ' ') {
        break;
      }
      Reverse(str,begin,j-1);
      i = j+1;
    }
  }
}

int main(int argc, char const *argv[]) {
  // char str[] ="my name is xiaozhuang";
  char str[] ="name";
  Reverse(str,0,4);
  // Reverse_second(str,22);
  printf("%c\n", str[0]);
  return 0;
}
