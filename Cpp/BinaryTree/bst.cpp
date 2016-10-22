#include <iostream>
#include <vector>
using namespace std;
/**
 * 将一个有序数组有序的插入到一个二叉搜索树中
 */
typedef struct Bin_tree BinTree;
struct  Bin_tree{
    int value;
    BinTree *right;
    BinTree *left;
};

/* 将数组插入BST */
void InsertFromArray(BinTree *&root , int *array, int start,int end) {
    if (start > end)
        return ;
    // 初始化一个节点
    root = new BinTree;
    root->left = NULL;
    root->right = NULL;
    //找到有序数组的中间节点作为根节点
    int mid = start + (end-start)/2;
    root->value = array[mid];
    // 然后递归调用创建坐左子树和右子树
    InsertFromArray(root->left,array,start,mid-1);
    InsertFromArray(root->right,array,mid+1,end);
}
/**
 * 中序遍历
 */
void Inorder(BinTree *root) {
    if (root == NULL)
        return ;
    Inorder(root->left);
    std::cout << root->value << std::endl;
    Inorder(root->right);
}

int main(int argc, char const *argv[]) {
    int array[]  = {1,2,3,4,5,6,7,8,9};
    BinTree *root = NULL;
    InsertFromArray(root,array,0,8);
    Inorder(root);
    return 0;
}
