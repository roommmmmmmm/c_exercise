#include <stdio.h>
/*
 stdin
 stdout
 stderr
 */
int main()
{
	//标准输出流
	fprintf(stdout,"Please input a value : \n");
	int a;
	//标准输入流
	fscanf(stdin,"%d",&a);
	if(a<0){
		//标准错误流
		fprintf(stderr,"the value must > 0");
		return 1;
	}
	return 0;
}
