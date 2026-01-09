class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {nullptr, 0};

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        if (l.second > r.second) return {l.first, l.second + 1};
        if (l.second < r.second) return {r.first, r.second + 1};
        return {root, l.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
