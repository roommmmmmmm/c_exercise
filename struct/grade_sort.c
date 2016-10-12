// 题目描述
//
// 查找和排序
//
// 题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
//       都按先录入排列在前的规则处理。
//
//    例示：
//    jack      70
//    peter     96
//    Tom       70
//    smith     67
//
//    从高到低  成绩
//    peter     96
//    jack      70
//    Tom       70
//    smith     67
//
//    从低到高
//
//    smith     67
//
//    Tom       70
//    jack      70
//    peter     96
//
// 输入描述:
//
// 输入多行，先输入要排序的人的个数，然后输入排序方法0（降序）或者1（升序）再分别输入他们的名字和成绩，以一个空格隔开
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char name[50];
    int grade;
} student;
void insertion_sort(student *,int , int);
void bubble_sort(student *,int , int);

int main(int argc, char const *argv[]) {
    int num,updown,i;
    student *stu;
    scanf("%d", &num);
    scanf("%d",&updown);
    stu = (student *)malloc(num * sizeof(student));
    for (i = 0; i < num; i++) {
        // scanf("%s %d",(stu+i)->name,&(stu+i)->grade);
        scanf("%s %d",stu[i].name,&stu[i].grade);
    }
    // insertion_sort(stu,num,updown);
    bubble_sort(stu,num,updown);
    for ( i = 0; i < num; i++) {
        printf("%s %d\n",(stu+i)->name,(stu+i)->grade );
    }
    return 0;
}
/**
 * 冒泡排序
 * @param stu    待排序的元素
 * @param num    元素个数
 * @param updown 排序方式
 */
void bubble_sort(student *stu,int num, int updown){
    if(num <= 1) return;
    student temp;
    int i , j;
    if (1 == updown) {
        //升序
        for ( i = 1; i < num; i++) {
            for ( j = num -1; j >= i; j--) {
                if (stu[j].grade < stu[j-1].grade) {
                    temp = stu[j-1];
                    stu[j-1] = stu[j];
                    stu[j] = temp;
                }
            }
        }
    }else if (0 == updown) {
        //降序
        for ( i = 1; i < num; i++) {
            for ( j = num -1; j >= i; j--) {
                if (stu[j].grade > stu[j-1].grade) {
                    temp = stu[j-1];
                    stu[j-1] = stu[j];
                    stu[j] = temp;
                }
            }
        }
    }
    return ;
}

/**
 * 插入排序
 * @param stu    待排序的元素
 * @param num    数据长度
 * @param updown 排序方法
 */
void insertion_sort(student *stu,int num, int updown){
    if (num <=1 ) return ;
    //升序
    if (1 == updown) {
        int i;
        for ( i = 1 ; i < num; i++) {
            student key = stu[i];
            int j  = i -1;
            while (j >=0 && key.grade < stu[j].grade) {
                stu[j + 1] = stu[j];
                j--;
            }
            stu[j + 1] = key;
        }
    }else if (0 == updown) { // 降序
        int i;
        for ( i = 1 ; i < num; i++) {
            student key = stu[i];
            int j  = i -1;
            while (j >=0 && key.grade > stu[j].grade) {
                stu[j + 1] = stu[j];
                j--;
            }
            stu[j + 1] = key;
        }
    }
    return ;
}
