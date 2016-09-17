/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 // 二叉树的最小深度为根节点到最近叶子节点的距离。
 //
 // 两种实现方法，一种就是计算左子树和右子树深度的时候，判断是否等于0，如果等于0，说明该子树不存在，深度赋值为最大值。
 //
 // 第二种就是判断左子树或右子树是否为空，若左子树为空，则返回右子树的深度，反之返回左子树的深度，如果都不为空，则返回左子树和右子树深度的最小值
int minDepth(struct TreeNode* root) {
    if(root == NULL) return 0;


    if(root->left == NULL && root->right == NULL)
        return 1;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if(left == 0) left = INT_MAX;
    if(right == 0) right = INT_MAX;

    return left<right ? left+1 : right+1;
}

int minDepth(TreeNode *root) {
        if(root == NULL)
            return false;

        if(root->left == NULL) return minDepth(root->right) + 1;
        if(root->right == NULL) return minDepth(root->left) + 1;

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        return leftDepth < rightDepth ? (leftDepth + 1) : (rightDepth + 1);
    }
