#include <stdio.h>
int get_big(int i , int j);

int (*get_function(int a))(int,int);

int main(){
  int i = 5, j = 10 ,max;
  int (*p)(int,int);
  p = get_function(100);
  max = p(i,j);
  printf("The Max number is %d\n",max );
  return 0;
}

int get_big(int i , int j){
  return i>j?i:j;
}

int (*get_function(int a))(int , int){
  printf("The number is %d\n",a);
  return get_big;
}
