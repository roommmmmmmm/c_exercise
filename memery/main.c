#include <stdio.h>

int global = 0;//定义一个全局的变量，用来做对比数据
/*
 * 定义矩形的面积计算公式 
 */
int rect(int height,int width){
	static int count = 0;
	count++;
	global++;
	int space = height * width;
	return space;
}

int square(int width){
	static int count = 0;
	count++;
	global++;
	int space = rect(width,width);
	return space;
}

int main(){
	int height = 3;
	int width = 5;
	int *pheight = &height;
	int *pwidth = &width;
	int *pglobal = &global;
	int (*psquare)(int width) = &square;
	int space = square(width);
	printf("The space is %d \n",space);
	return 0;
}
