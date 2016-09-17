// 给定由大写，小写字母和空格组成的字符串，返回 最后 一个单词的长度。
//
// 如果输入中不存在单词，返回 000。
//
// 注意：
//
// “单词”是指不包含空格符号的字符串

#include <stdio.h>
#include <string.h>

int main(){
	char s[10000];
	int count = 0,i,c;
	gets(s);
	for(i = strlen(s)-1;i > 0;i--)
	{
		if(s[i] != ' ')
			count++;
		if(count > 0)
			if(s[i] == ' ')
				break;
	}
	printf("%d\n",count);
	return 0;
}
