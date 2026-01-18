class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(n, vector<int>(m + 1, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                row[i][j + 1] = row[i][j] + grid[i][j];

        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++)
                col[j][i + 1] = col[j][i] + grid[i][j];

        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int target = row[i][j + k] - row[i][j];
                    bool ok = true;

                    for (int r = i; r < i + k; r++) {
                        if (row[r][j + k] - row[r][j] != target) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;

                    for (int c = j; c < j + k; c++) {
                        if (col[c][i + k] - col[c][i] != target) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;

                    int d1 = 0, d2 = 0;
                    for (int x = 0; x < k; x++) {
                        d1 += grid[i + x][j + x];
                        d2 += grid[i + x][j + k - 1 - x];
                    }

                    if (d1 == target && d2 == target)
                        return k;
                }
            }
        }
        return 1;
    }
};
