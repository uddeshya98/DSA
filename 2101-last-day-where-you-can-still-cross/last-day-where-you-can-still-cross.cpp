class DSU {
public:
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        int TOP = n, BOTTOM = n + 1;
        DSU dsu(n + 2);
        vector<vector<char>> land(row, vector<char>(col, 0));

        auto id = [&](int r, int c) { return r * col + c; };
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int i = (int)cells.size() - 1; i >= 0; --i) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            land[r][c] = 1;

            int cur = id(r, c);
            if (r == 0) dsu.unite(cur, TOP);
            if (r == row - 1) dsu.unite(cur, BOTTOM);

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
                if (!land[nr][nc]) continue;
                dsu.unite(cur, id(nr, nc));
            }

            if (dsu.find(TOP) == dsu.find(BOTTOM)) return i;
        }
        return 0;
    }
};
