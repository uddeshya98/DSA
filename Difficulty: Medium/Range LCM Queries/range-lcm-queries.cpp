class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    void build(int node, int start, int end, const vector<int>& arr, vector<long long>& tree) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, arr, tree);
        build(2 * node + 1, mid + 1, end, arr, tree);
        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val, vector<long long>& tree) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val, tree);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val, tree);
        }
        tree[node] = lcm(tree[2 * node], tree[2 * node + 1]);
    }

    long long query(int node, int start, int end, int l, int r, const vector<long long>& tree) {
        if (r < start || end < l) return 1;
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        long long p1 = query(2 * node, start, mid, l, r, tree);
        long long p2 = query(2 * node + 1, mid + 1, end, l, r, tree);
        return lcm(p1, p2);
    }

    vector<long long> RangeLCMQuery(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<long long> tree(4 * n, 1);
        if (n > 0) build(1, 0, n - 1, arr, tree);

        vector<long long> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                update(1, 0, n - 1, q[1], q[2], tree);
            } else if (q[0] == 2) {
                ans.push_back(query(1, 0, n - 1, q[1], q[2], tree));
            }
        }
        return ans;
    }
};