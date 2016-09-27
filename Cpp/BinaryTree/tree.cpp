#include<iostream>
#include<string>
using namespace std;
class Node {
public:
    char data;
    Node *lchild, *rchild;
    Node(char _data) {
        data = _data;
        lchild = NULL;
        rchild = NULL;
    }
    ~Node() {
        if (lchild != NULL) {
            delete lchild;
        }
        if (rchild != NULL) {
            delete rchild;
        }
    }
    void postorder() {
        if (lchild != NULL) {
            lchild->postorder();
        }
        if (rchild != NULL) {
            rchild->postorder();
        }
        cout <<data;
    }
    Node* build(const string &pre_str,const string &in_str,int len){
        Node *p = new Node(pre_str[0] );//root Node;
        int pos = in_str.find(pre_str[0]);
        if(pos>0){             //递归建立根节点的左子树
             p->lchild = build (pre_str.substr(1,pos),in_str.substr(0,pos),pos);
        }
        if(len-pos-1>0){        //递归建立根节点的右子树
            p->rchild = build (pre_str.substr(pos+1),in_str.substr(pos+1),len-pos-1);
        }
        return p;
    }
    Node* buildmirror(const string &pre_str,const string &in_str,int len){     //  建立镜子中的二叉树
        Node *p = new Node(pre_str[0] );//root Node;
        int pos = in_str.find(pre_str[0]);
        if(len-pos-1>0){             //递归建立根节点的左子树,把原来的右子树换成左子树；
             p->lchild = buildmirror (pre_str.substr(pos+1),in_str.substr(pos+1),len-pos-1);

        }
        if(pos>0){        //递归建立根节点的右子树，把原来的左子树换成右子树；
            p->rchild = buildmirror (pre_str.substr(1,pos),in_str.substr(0,pos),pos);
        }
        return p;
    }

};
class BinaryTree {
private:
    Node *root;
public:
    BinaryTree() {
        root = NULL;
    }
    ~BinaryTree() {
        if (root != NULL) {
            delete root;
        }
    }
    BinaryTree(const string &pre_str,const string &in_str,int len) {
       root = root->build(pre_str,in_str,len);
    }
    BinaryTree(int a,const string &pre_str,const string &in_str,int len) {
       root = root->buildmirror(pre_str,in_str,len);
    }
    void postorder() {
        root->postorder();
    }
};
int main() {

    string pre_str , in_str ;
    cin >> pre_str >> in_str;
    BinaryTree binarytree(pre_str,in_str,in_str.length());
    binarytree.postorder();  //输出二叉树后序遍历
    cout<<endl;
    BinaryTree binarytree2(1,pre_str,in_str,in_str.length());
    binarytree2.postorder();   //输出镜子中二叉树的后序遍历
    return 0;
}
