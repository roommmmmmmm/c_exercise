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
    int TreeDepth(TreeNode* pRoot)
    {
        //递归解法
    	//if(!pRoot) return 0;
        //	return max(1+TreeDepth(pRoot->left),1+TreeDepth(pRoot->right));
        //非递归解法
        if(!pRoot) return 0;
        queue<TreeNode *> q;

        q.push(pRoot);

        int depth = 0;

        while(!q.empty()){
            int len = q.size();
            depth++;
            while(len--){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return depth;
    }
};

// 题目描述
// 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
