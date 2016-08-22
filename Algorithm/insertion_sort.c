#include <stdio.h>

int main(int argc, char const *argv[]) {
  int A[20] = {5,6,8,95,30,21,15,90,25,9,20,33,10,11,1,66,71,89,28,20};
  int i ,x ,j ;
  //insertion sort
  for ( i = 1; i < 20; i++) {
    x=A[i];
    for ( j = i -1; j >=0; j--) {
      if (A[j] > x) {
        A[j+1] = A[j];
      }else{
        A[j+1] = x;
        break;
      }
    }
    if (j<0) {
      A[0] = x;
    }
  }
  for ( i = 0; i < 20; i++) {
    printf("%d\n",A[i] );
  }
  printf("\n" );

  return 0;
}
