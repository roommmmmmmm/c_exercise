#include <stdio.h>

struct superman{
	char name[20];
	int age;
	int atk;
	char superpower[20];		
};

int main(){
	struct superman girl = {"Black Widow",18,20000,"SM"};
	printf("name is %s \n",girl.name);
	struct superman boy[2] = {
		{"Captain",100,5000,"shield"},		
		{"Iron Man",30,15000,"fly"}		
	};
	printf("%s's power is %s \n",boy[0].name,boy[0].superpower);
	printf("%s's power is %s \n",boy[1].name,boy[1].superpower);
	return 0;		
}
