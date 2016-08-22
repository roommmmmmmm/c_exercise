#include <stdio.h>
int Q[100];
int Head,Tail,Number_of_Items = 0;

void Enqueue(int x) {
  if (Number_of_Items == 0) {
    Head =Tail= 0;
    Q[0] = x;
  }else{
    Tail = (Tail +1) % 100;
    Q[Tail] = x;
  }
  Number_of_Items++;
}
int Dequeue() {
  int z;
  z = Q[Head];
  Head = (Head + 1 ) % 100;
  Number_of_Items--;
  return z;
}
int main() {
  int i,j,n,answer;
  printf("Please enter an integer: \n" );
  scanf("%d",&n );
  for ( i = 1; i <= n; i++) {
    Enqueue(i);
  }
  for ( i = 1; i < n-1; i++) {
    j = Dequeue();
    Dequeue();
    Enqueue(j);
  }
  answer = Q[Head];
  printf("The value of J(%d) is %d\n",n,answer );
  return 0;
}
