#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int _data){
        data = _data;
        next = NULL;
    }
};
class LinkList{
private:
    Node *head;
public:
    LinkList(){
        head = NULL;
    }
};
int main() {
    LinkList linklist;
    return 0;
}
