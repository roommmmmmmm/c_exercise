#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
/**
 * 二叉搜索树的创建
 * 二叉树的递归遍历
 * 二叉树的非递归遍历
 */
typedef struct Bin_Tree BinTree;
struct Bin_Tree{
    int value;
    BinTree *right;
    BinTree *left;
};
/**
 * 构造二叉搜索树
 */
BinTree* InsertNode(BinTree *root,int value){
    BinTree *newnode = new BinTree;
    newnode->value = value;
    newnode->right = NULL;
    newnode->left = NULL;

    if (root == NULL ) {
        root = newnode;
    }else{
        BinTree *parent = root;
        while (parent != NULL) {
            if (parent->value < value) {
                if(parent->right == NULL)
                    break;
                else
                    parent=parent->right;
            }else{
                if(parent->left == NULL)
                    break;
                else
                    parent = parent->left;
            }
        }
        if (parent->value < value)
            parent->right = newnode;
        else
            parent->left = newnode;
    }
    return root;
}
/**
 * 查找二叉树搜索树的最大值
 */
BinTree* Max(BinTree *root){
    if(root == NULL)
        return ;
    BinTree *temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}
/**
 * 查找二叉树搜索树的最小值
 */
BinTree* Min(BinTree *root){
    if(root == NULL)
        return ;
    BinTree *temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}
/**
 * 在二叉搜索树中查找元素
 */
BinTree* Search(BinTree *root,BinTree* &parent,int value){
    if(root == NULL)
        return ;
    BinTree *temp = root;
    parent = NULL;
    while (temp != NULL) {
        if (temp->value == value) {
            break ;
        }else{
            parent = temp;
            if(temp->value > value)
                temp = temp->left;
            else
                temp = temp->right;
        }
    }
    if (temp==NULL) {
        parent = NULL;
        return NULL;
    }
    return temp;
}
