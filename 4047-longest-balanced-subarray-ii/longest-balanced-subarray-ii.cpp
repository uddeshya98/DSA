class Solution {
    struct Node {
        int min_val;
        int max_val;
        int lazy;
    };

    vector<Node> tree;
    int n;

    void push(int v) {
        if (tree[v].lazy != 0) {
            tree[2 * v].min_val += tree[v].lazy;
            tree[2 * v].max_val += tree[v].lazy;
            tree[2 * v].lazy += tree[v].lazy;

            tree[2 * v + 1].min_val += tree[v].lazy;
            tree[2 * v + 1].max_val += tree[v].lazy;
            tree[2 * v + 1].lazy += tree[v].lazy;

            tree[v].lazy = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int add) {
        if (l > r) return;
        if (l == tl && r == tr) {
            tree[v].min_val += add;
            tree[v].max_val += add;
            tree[v].lazy += add;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), add);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
            tree[v].min_val = min(tree[2 * v].min_val, tree[2 * v + 1].min_val);
            tree[v].max_val = max(tree[2 * v].max_val, tree[2 * v + 1].max_val);
        }
    }

    int query(int v, int tl, int tr) {
        if (tree[v].min_val > 0 || tree[v].max_val < 0) return -1;
        if (tl == tr) return tl;
        push(v);
        int tm = (tl + tr) / 2;
        int res = query(2 * v, tl, tm);
        if (res != -1) return res;
        return query(2 * v + 1, tm + 1, tr);
    }

public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n + 1, {0, 0, 0});
        
        vector<int> last(100005, 0);
        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];
            int prev = last[x];
            int val = (x % 2 != 0) ? 1 : -1;

            update(1, 1, n, prev + 1, i, val);
            last[x] = i;

            int idx = query(1, 1, n);
            if (idx != -1 && idx <= i) {
                ans = max(ans, i - idx + 1);
            }
        }
        return ans;
    }
};