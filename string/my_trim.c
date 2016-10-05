#include <stdio.h>
#include <string.h>

char *my_trim(char *str,const char *cset){
  char *start,*end,*sp,*ep;

  sp = start = str;
  ep = end = str + strlen(str) - 1;

  while(sp <= end && strchr(cset,*sp)) sp++;
  while(ep > start && strchr(cset,*ep)) ep--;
  size_t len = (sp > ep) ? 0 : ((ep-sp)+1);

  //printf("%.*s\n",(ep-sp)+1,sp);

  if(str != sp) memmove(str, sp, len);

  str[len] = '\0';
  return str;
}

int main(int argc, char const *argv[]) {
  char s[] = "hello,world";
  const char *ch = "ld";
  char *str = my_trim(s,ch);
  // printf("%s\n",str);
  return 0;
}
