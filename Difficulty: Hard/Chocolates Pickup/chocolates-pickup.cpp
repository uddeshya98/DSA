class Solution {
public:
    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        
        dp[0][m - 1] = grid[0][0] + grid[0][m - 1];

        for (int i = 1; i < n; ++i) {
            vector<vector<int>> next_dp(m, vector<int>(m, -1));
            for (int j1 = 0; j1 < m; ++j1) {
                for (int j2 = 0; j2 < m; ++j2) {
                    if (dp[j1][j2] != -1) {
                        for (int d1 = -1; d1 <= 1; ++d1) {
                            for (int d2 = -1; d2 <= 1; ++d2) {
                                int nj1 = j1 + d1;
                                int nj2 = j2 + d2;
                                
                                if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                    int val = dp[j1][j2];
                                    if (nj1 == nj2) {
                                        val += grid[i][nj1];
                                    } else {
                                        val += grid[i][nj1] + grid[i][nj2];
                                    }
                                    next_dp[nj1][nj2] = max(next_dp[nj1][nj2], val);
                                }
                            }
                        }
                    }
                }
            }
            dp = next_dp;
        }

        int max_choc = 0;
        for (int j1 = 0; j1 < m; ++j1) {
            for (int j2 = 0; j2 < m; ++j2) {
                max_choc = max(max_choc, dp[j1][j2]);
            }
        }
        
        return max_choc;
    }
};