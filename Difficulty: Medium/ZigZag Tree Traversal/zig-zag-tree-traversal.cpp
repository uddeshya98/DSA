class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level(sz);
            for (int i = 0; i < sz; i++) {
                Node* cur = q.front(); q.pop();
                int idx = leftToRight ? i : (sz - 1 - i);
                level[idx] = cur->data;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ans.insert(ans.end(), level.begin(), level.end());
            leftToRight = !leftToRight;
        }
        return ans;
    }
};
