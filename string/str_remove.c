#include <stdio.h>
#include <stdlib.h>
/**
 * 一个已经排序的字符串，将重复的字符串保留一个
 */
void Remove(char *str) {
  int index = 0;
  int pos;
  for ( pos = 1; str[pos] != '\0'; pos++) {
    if (str[pos] != str[index]) {
      index++;
      str[index]=str[pos];
    }
  }
  str[index+1]='\0';
}
/**
 * 一个已经排序的字符串，将重复的字符串保留两个
 */
void Remove2(char *str) {
  int index = 0;
  int pos;
  int flag = 0;
  for ( pos = 1; str[pos] != '\0'; pos++) {
    if (str[pos] != str[index]) {
      index++;
      str[index] = str[pos];
      flag = 0;
    }else{
      if (flag == 0) {
        index++;
        str[index] = str[pos];
        flag = 1;
      }
    }
  }
  str[index+1]='\0';
}
//删除全部重复的字符串
void Remove_all(char *str) {
  int index = -1;
  int pos;
  int flag = 0;
  for ( pos = 1; str[pos] != '\0'; pos++) {
    //当前字符和下一个字符相同
    if (str[pos] == str[pos+1]) {
      flag = 1;
    }
    //当前字符和下一个字符不同
    else{
      if (flag == 1) {
        flag= 0;
      }else{
        index++;
        str[index] = str[pos];
      }
    }
  }
  if (str[pos] != str[pos-1]) {
    str[++index] = str[pos];
  }
  str[index+1] = '\0';
}
int main(int argc, char const *argv[]) {
  char str[] = "AAABCCCDDDFFFIIIIMMMQWWEEEWEW";
  printf("%s\n", str);
  // Remove(str);
  // Remove2(str);
  Remove_all(str);
  printf("%s\n", str);
  return 0;
}
