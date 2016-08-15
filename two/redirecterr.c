#include <stdio.h>

int main(){
	int foo,bar;
	printf("Please input divisor : \n");
	scanf("%d",&foo);
	printf("Please input dividend : \n");
	scanf("%d",&bar);
	if(0 != bar){
	printf("%d / %d = %d",foo,bar,foo/bar);
	}else{
	printf("Error : The dividend is not equal to 0 !!");
	return 1;
	}
	return 0;
}
