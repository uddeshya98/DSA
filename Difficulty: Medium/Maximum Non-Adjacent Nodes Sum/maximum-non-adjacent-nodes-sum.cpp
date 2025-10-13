class Solution {
  public:

    pair<long long,long long> dfs(Node* root) {
        if (!root) return {0, 0};
        auto L = dfs(root->left);
        auto R = dfs(root->right);
        long long inc = root->data + L.second + R.second; // include this node
        long long exc = max(L.first, L.second) + max(R.first, R.second); // exclude this node
        return {inc, exc};
    }

    int getMaxSum(Node *root) {
        auto res = dfs(root);
        long long ans = max(res.first, res.second);
        return (int)ans;
    }
};