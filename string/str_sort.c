#include <stdio.h>
#include <stdlib.h>

/**
 * 字符串排序，大写字符在前，小写字符在后
 */
void str_sort(char *str) {
  int index = -1;
  int pos;
  char temp;
  for (pos = 0; str[pos] != '\0'; pos++) {
    if (str[pos] >= 'A' && str[pos] <= 'Z') {
      index++;
      temp = str[index];
      str[index] = str[pos];
      str[pos] = temp;
    }
  }
}
//不改变相对位置
void str_Sort(char *str) {
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  int index = len;
  int pos;
  char temp;
  for ( pos = len -1; str[pos] != '\0' ; pos--) {
    if (str[pos] >= 'a' && str[pos] <= 'z') {
      index--;
      temp = str[index];
      str[index] = str[pos];
      str[pos] = temp;
    }
  }
}
int main(int argc, char const *argv[]) {
  char str[] = "asdBKLkasldlkBVSAjhkLasdDliLKK";
  printf("%s\n",str );
  // str_sort(str);
  // printf("%s\n",str );
  str_Sort(str);
  printf("%s\n",str);
  return 0;
}
