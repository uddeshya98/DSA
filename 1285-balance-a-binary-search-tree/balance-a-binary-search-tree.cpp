class Solution {
public:
    vector<int> inorderVals;
    
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        inorderVals.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(int l, int r) {
        if(l > r) return nullptr;
        int m = (l + r) / 2;
        TreeNode* node = new TreeNode(inorderVals[m]);
        node->left = build(l, m - 1);
        node->right = build(m + 1, r);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, inorderVals.size() - 1);
    }
};
