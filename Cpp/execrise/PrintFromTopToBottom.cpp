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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
		vector<int> result;

        if(root == NULL) return result;

        queue<TreeNode *> myqueue;

        myqueue.push(root);

        while(!myqueue.empty()){
            TreeNode *tree = myqueue.front();
            result.push_back(tree->val);
            myqueue.pop();

            if(tree->left != NULL) myqueue.push(tree->left);

            if(tree->right != NULL) myqueue.push(tree->right);

        }
        return result;
    }
};

// 题目描述
// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
// 二叉树的广度遍历，利用队列来实现
