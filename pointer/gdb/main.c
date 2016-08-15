#include <stdio.h>

void change(int foo,int bar){
	int tmp=foo;
	foo=bar;
	bar=tmp;
}
int main(){
	int foo = 1;
	int bar = 2;
	change(foo,bar);
	printf("foo = %d \nbar = %d \n",foo,bar);
	return 0;
}
