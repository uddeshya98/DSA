class Solution {
public:
    vector<int> parent, rankv;

    int findp(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findp(parent[x]);
    }

    void unite(int a, int b) {
        a = findp(a);
        b = findp(b);
        if (a == b) return;
        if (rankv[a] < rankv[b]) parent[a] = b;
        else if (rankv[b] < rankv[a]) parent[b] = a;
        else parent[b] = a, rankv[a]++;
    }

    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unite(i, j);
                }
            }
        }

        unordered_set<int> s;
        for (int i = 0; i < n; i++) s.insert(findp(i));

        return n - (int)s.size();
    }
};
