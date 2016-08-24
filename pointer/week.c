#include <stdio.h>
#include <string.h>
char *name[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

char *message = "wrong input";

char *week(int day);

int main(){
  int day;
  char *p;

  printf("Please input a number of a week : \n");
  scanf("%d",&day);

  p = week(day);
  printf("%s\n", p);
  return 0;
}

char *week(int day){
  if (day < 0 || day > 7) {
    return message;
  }else{
    return name[day-1];
  }
}
