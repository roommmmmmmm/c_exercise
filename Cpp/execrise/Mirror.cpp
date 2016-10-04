/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if(pRoot == NULL) return ;

        /*TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;

        if(pRoot->left){
            Mirror(pRoot->left);
        }
        if(pRoot->right){
            Mirror(pRoot->right);
        }*/

        stack<TreeNode*> mystack;

        mystack.push(pRoot);
        while(mystack.size()){
            TreeNode *tree = mystack.top();
            mystack.pop();

            if(tree->left != NULL || tree->right != NULL){
                TreeNode *temp = tree->left;
                tree->left = tree->right;
                tree->right = temp;
            }
            if(tree->left) mystack.push(tree->left);
            if(tree->right) mystack.push(tree->right);
        }
    }
};

// 题目描述
// 操作给定的二叉树，将其变换为源二叉树的镜像。
// 输入描述:
//
// 二叉树的镜像定义：源二叉树
//     	    8
//     	   /  \
//     	  6   10
//     	 / \  / \
//     	5  7 9 11
//     	镜像二叉树
//     	    8
//     	   /  \
//     	  10   6
//     	 / \  / \
//     	11 9 7  5
