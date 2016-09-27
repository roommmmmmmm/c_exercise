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
};
int main() {
    BinaryTree binarytree;
    int arr[10] = { 8, 9, 10, 3, 2, 1, 6, 4, 7, 5 };
    for (int i = 0; i < 10; i++) {
        binarytree.insert(arr[i]);
    }
    int value;
    cin >> value;
    if (binarytree.find(value)) {
        cout << "search success!" << endl;
    } else {
        cout << "search failed!" << endl;
    }
    return 0;
}
