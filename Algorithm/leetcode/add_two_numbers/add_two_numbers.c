#include<stdio.h>
#include<math.h>
#include<malloc.h>
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* new_node;
    struct ListNode* p;
    int carry=0,sum,val1,val2;//进位

    p = head;
    while(l1!=NULL || l2!=NULL || carry!=0)
    {
        val1 = (l1==NULL) ? 0 : l1->val;
        val2 = (l2==NULL) ? 0 : l2->val;
        sum = val1 + val2 + carry;
        carry = sum/10;
        p->val = sum%10;
        p->next = NULL;

        l1 = (l1==NULL) ? NULL : l1->next;
        l2 = (l2==NULL) ? NULL : l2->next;
        //判断是否有必要新建节点
        if(l1!=NULL || l2!=NULL || carry!=0)
        {
            new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
            new_node->next = NULL;
            new_node->val = 1;//指定为1，若进位必为1
            p->next = new_node;
            p = p->next;
        }
    }
    return head;
}

void main()
{
    struct ListNode *l,*p;
    struct ListNode *l0 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l6 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l7 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l8 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l9 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l0->val = 9;
    l1->val = 1;
    l2->val = 9;
    l3->val = 9;
    l4->val = 9;
    l5->val = 9;
    l6->val = 9;
    l7->val = 9;
    l8->val = 9;
    l9->val = 9;


    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;
    l5->next=l6;
    l6->next=l7;
    l7->next=l8;
    l8->next=l9;
    l9->next=NULL;
    l0->next=NULL;

    l = addTwoNumbers(l0,l1);
    for(p=l;p!=NULL;p=p->next)
        printf("%d",p->val);
}
