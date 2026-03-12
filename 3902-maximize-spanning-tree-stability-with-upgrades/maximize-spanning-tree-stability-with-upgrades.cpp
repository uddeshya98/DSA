class Solution {
    struct DSU {
        vector<int> parent, rank;
        int components;
        
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; ++i) parent[i] = i;
            components = n;
        }
        
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        
        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                if (rank[root_i] < rank[root_j]) {
                    parent[root_i] = root_j;
                } else if (rank[root_i] > rank[root_j]) {
                    parent[root_j] = root_i;
                } else {
                    parent[root_j] = root_i;
                    rank[root_i]++;
                }
                components--;
                return true;
            }
            return false;
        }
    };

    bool check(int mid, int n, const vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < mid) return false;
                dsu.unite(e[0], e[1]);
            }
        }
        
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] >= mid) {
                dsu.unite(e[0], e[1]);
            }
        }
        
        int upgrades = 0;
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < mid && 2LL * e[2] >= mid) {
                if (dsu.unite(e[0], e[1])) {
                    upgrades++;
                }
            }
        }
        
        return dsu.components == 1 && upgrades <= k;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU initial_dsu(n);
        int min_must_s = 200005;
        
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (!initial_dsu.unite(e[0], e[1])) return -1;
                min_must_s = min(min_must_s, e[2]);
            }
        }
        
        DSU full_dsu(n);
        for (const auto& e : edges) {
            full_dsu.unite(e[0], e[1]);
        }
        if (full_dsu.components > 1) return -1;

        int low = 1, high = min(200000, min_must_s);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, n, edges, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};