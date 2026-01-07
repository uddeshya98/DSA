class Solution {
public:
    long long totalSum = 0;
    long long maxProductVal = 0;
    const int MOD = 1e9 + 7;

    
    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subTreeSum = root->val + leftSum + rightSum;

     
        long long product = subTreeSum * (totalSum - subTreeSum);
        maxProductVal = max(maxProductVal, product);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return maxProductVal % MOD;
    }
};
