// 样例输入
// 11100101
// 00101011
//
// 样例输出
//
// 00110001
#include<stdio.h>
#include<string.h>
int main()
{
    char a[50], b[50], c[50];
    int i=0, j=0;
    int na, nb;
    scanf("%s", a);
    scanf("%s", b);
    na = strlen(a);
    nb = strlen(b);
    if(na < 1 || na > 50 || nb < 1 || nb > 50 || na != nb)
        return 0;
    while(i < na)
    {
        if(a[i] == b[i])
            c[i] = '1';
        else
            c[i] = '0';
        i++;
    }
    for(i = 0; i < na; i++)
        printf("%c", c[i]);
    return 0;
}
