class Solution {
    int maxSum;

    int findPathSum(Node* root) {
        if (!root) return 0;
        int left = max(0, findPathSum(root->left));
        int right = max(0, findPathSum(root->right));
        maxSum = max(maxSum, left + right + root->data);
        return root->data + max(left, right);
    }

public:
    int findMaxSum(Node* root) {
        maxSum = INT_MIN;
        findPathSum(root);
        return maxSum;
    }
};
