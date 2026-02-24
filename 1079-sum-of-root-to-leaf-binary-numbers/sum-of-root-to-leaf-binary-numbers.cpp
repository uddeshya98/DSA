class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* node, int val) {
        if (!node) return 0;
        val = (val << 1) | node->val;
        if (!node->left && !node->right) return val;
        return dfs(node->left, val) + dfs(node->right, val);
    }
};