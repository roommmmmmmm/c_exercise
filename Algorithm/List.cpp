#include <iostream>
using namespace std;

struct List
{
    int num;
    List *next;
};

//在下一行建立头指针
List *head;

List *Create()
{
    //从下一行开始构造单链表
    List *p=NULL;
    List *q=NULL;
    head = NULL;
    for (int i =0;i<3;i++){
        p=new List;
        cin>>p->num;
        if(head == NULL){
            head = p;
        }else{
        q->next = p;
        }
        q =p;
    }
    if(head != NULL){
        q->next=NULL;
    }
    return head;
}

void displayList(List *head)
{
    while ( head != NULL ) {
        cout << head->num << endl;
        head = head->next;
    }
}

int main() {
    Create();
    displayList(head);
    return 0;
}
