#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node *lchild, *rchild, *father;
    Node(int _data, Node *_father = NULL) {
        data = _data;
        lchild = NULL;
        rchild = NULL;
        father = _father;
    }
    ~Node() {
        if (lchild != NULL) {
            delete lchild;
        }
        if (rchild != NULL) {
            delete rchild;
        }
    }
    void insert(int value) {
        if (value == data) {
            return;
        } else if (value > data) {
            if (rchild == NULL) {
                rchild = new Node(value, this);
            } else {
                rchild->insert(value);
            }
        } else {
            if (lchild == NULL) {
                lchild = new Node(value, this);
            } else {
                lchild->insert(value);
            }
        }
    }
    Node* search(int value) {
        if (data == value) {
            return this;
        } else if (value > data) {
            if (rchild == NULL) {
                return NULL;
            } else {
                return rchild->search(value);
            }
        } else {
            if (lchild == NULL) {
                return NULL;
            } else {
                return lchild->search(value);
            }
        }
    }
    /**
     * 查找节点的前驱节点
     * @return 节点
     */
    Node* predecessor(){
        Node *temp = lchild;
        while(temp != NULL && temp->rchild != NULL){
            temp = temp->rchild;
        }
        return temp;
    }
    /**
     * 找到节点的后继节点
     * @return 节点
     */
    Node* successor(){
        Node *temp = rchild;
        while(temp != NULL && temp->lchild != NULL){
            temp = temp->lchild;
        }
        return temp;
    }
    /**
     * 删除度为1和0的节点
     * @param delete_node 需要删除的节点
     */
    void remove_node(Node *delete_node){
        Node *temp = NULL;
        if(delete_node->lchild != NULL){
            temp = delete_node->lchild;
            temp->father = delete_node->father;
            delete_node->lchild = NULL;
        }
        if(delete_node->rchild != NULL){
            temp = delete_node->rchild;
            temp->father = delete_node->father;
            delete_node->rchild = NULL;
        }
        if(delete_node->father->lchild == delete_node){
            delete_node->father->lchild = temp;
        }else{
            delete_node->father->rchild = temp;
        }
        delete delete_node;
    }
    bool delete_tree(int value){
        Node *delete_node,*current_node;
        current_node = search(value);
        if(current_node == NULL){
            return false;
        }
        if(current_node->lchild != NULL){
            delete_node = current_node->predecessor();
        }else if(current_node->rchild != NULL){
            delete_node = current_node->successor();
        }else{
            delete_node = current_node;
        }
        current_node->data = delete_node->data;
        remove_node(delete_node);
        return true;
    }
    void preorder() {
        cout << data << " ";
        if (lchild != NULL) {
            lchild->preorder();
        }
        if (rchild != NULL) {
            rchild->preorder();
        }
    }
    void inorder() {
        if (lchild != NULL) {
            lchild->inorder();
        }
        cout << data << " ";
        if (rchild != NULL) {
            rchild->inorder();
        }
    }
    void postorder() {
        if (lchild != NULL) {
            lchild->postorder();
        }
        if (rchild != NULL) {
            rchild->postorder();
        }
        cout << data << " ";
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
    void insert(int value) {
        if (root == NULL) {
            root = new Node(value);
        } else {
            root->insert(value);
        }
    }
    bool find(int value) {
        if (root->search(value) == NULL) {
            return false;
        } else {
           return true;
        }
    }
    bool delete_tree(int value){
        return root->delete_tree(value);
    }
    void preorder() {
        root->preorder();
    }
    void inorder() {
        root->inorder();
    }
    void postorder() {
        root->postorder();
    }
};
int main() {
    BinaryTree binarytree;
    int arr[10] = { 8, 9, 10, 3, 2, 1, 6, 4, 7, 5 };
    // for (int i = 0; i < 10; i++) {
    //     cout << arr[i] << endl;
    //     // binarytree.insert(arr[i]);
    // }
    for(auto i:arr){
        std::cout << i << std::endl;
        binarytree.insert(i);
    }
    binarytree.preorder();
    cout << endl;
    binarytree.inorder();
    cout << endl;
    binarytree.postorder();
    cout << endl;
    int value;
    // cin >> value;
    // if (binarytree.find(value)) {
    //     cout << "search success!" << endl;
    // } else {
    //     cout << "search failed!" << endl;
    // }
    cin >> value;
    if(binarytree.delete_tree(value)){
        cout << "delete success!" << endl;
    }else{
        cout << "delete failed!" << endl;
    }
    binarytree.preorder();
    cout << endl;
    binarytree.inorder();
    cout << endl;
    binarytree.postorder();
    cout << endl;
    return 0;
}
