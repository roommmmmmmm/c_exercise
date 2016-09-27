/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*  思路：
*  因为顺序表，借助另一个循序表，依次把输入的循序表元素放到另一个中，那么就可以得到翻转后的顺序表
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> v;
        while(head != NULL)
        {
            v.insert(v.begin(),head->val);
            head = head->next;
        }
        return v;
    }
};
// 链表从尾到头输出，利用递归实现，不使用库函数直接printf输出的时候用递归比较好 
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> value;
        if(head != NULL)
        {
            value.insert(value.begin(),head->val);
            if(head->next != NULL)
            {
                vector<int> tempVec = printListFromTailToHead(head->next);
                if(tempVec.size()>0)
                value.insert(value.begin(),tempVec.begin(),tempVec.end());
            }

        }
        return value;
    }
};
//用库函数，每次扫描一个节点，将该结点数据存入vector中，如果该节点有下一节点，将下一节点数据直接插入vector最前面，直至遍历完，或者直接加在最后，最后调用reverse
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> value;
        if(head != NULL)
        {
            value.insert(value.begin(),head->val);
            while(head->next != NULL)
            {
                value.insert(value.begin(),head->next->val);
                head = head->next;
            }

        }
        return value;
    }
};
