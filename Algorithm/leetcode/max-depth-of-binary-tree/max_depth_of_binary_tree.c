// 二叉树的深度为根节点到最远叶子节点的距离。
//
// 如果二叉树为空，则深度为0
// 如果不为空，分别求左子树的深度和右子树的深度，去最大的再加1，因为根节点深度是1，要加进去。

int maxDepth(TreeNode *root) {

        if(root == NULL)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
    }
