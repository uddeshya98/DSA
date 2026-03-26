class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        for (auto& row : grid)
            for (int x : row) total += x;

        {
            unordered_map<int, vector<int>> rowOf;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    rowOf[grid[i][j]].push_back(i);

            long long topSum = 0;
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) topSum += grid[i][j];
                long long diff = topSum - (total - topSum);
                if (diff == 0) return true;

                auto canRemove = [&](long long val, int r1, int r2) -> bool {
                    if (val <= 0 || val > 100000) return false;
                    int v = (int)val, h = r2 - r1 + 1;
                    if (h == 1 && n == 1) return false;
                    if (h == 1) return grid[r1][0] == v || grid[r1][n-1] == v;
                    if (n == 1) return grid[r1][0] == v || grid[r2][0] == v;
                    auto it = rowOf.find(v);
                    if (it == rowOf.end()) return false;
                    auto& rows = it->second;
                    auto lo = lower_bound(rows.begin(), rows.end(), r1);
                    return lo != rows.end() && *lo <= r2;
                };

                if (diff > 0 && canRemove(diff,  0,   i  )) return true;
                if (diff < 0 && canRemove(-diff, i+1, m-1)) return true;
            }
        }

        {
            unordered_map<int, vector<int>> colOf;
            for (int j = 0; j < n; j++)
                for (int i = 0; i < m; i++)
                    colOf[grid[i][j]].push_back(j);

            long long leftSum = 0;
            for (int j = 0; j < n - 1; j++) {
                for (int i = 0; i < m; i++) leftSum += grid[i][j];
                long long diff = leftSum - (total - leftSum);
                if (diff == 0) return true;

                auto canRemove = [&](long long val, int c1, int c2) -> bool {
                    if (val <= 0 || val > 100000) return false;
                    int v = (int)val, w = c2 - c1 + 1;
                    if (m == 1 && w == 1) return false;
                    if (m == 1) return grid[0][c1] == v || grid[0][c2] == v;
                    if (w == 1) return grid[0][c1] == v || grid[m-1][c1] == v;
                    auto it = colOf.find(v);
                    if (it == colOf.end()) return false;
                    auto& cols = it->second;
                    auto lo = lower_bound(cols.begin(), cols.end(), c1);
                    return lo != cols.end() && *lo <= c2;
                };

                if (diff > 0 && canRemove(diff,  0,   j  )) return true;
                if (diff < 0 && canRemove(-diff, j+1, n-1)) return true;
            }
        }

        return false;
    }
};