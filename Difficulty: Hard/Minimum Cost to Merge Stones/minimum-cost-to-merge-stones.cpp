class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;

        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++)
            prefix[i+1] = prefix[i] + stones[i];

        auto sum = [&](int i, int j){
            return prefix[j+1] - prefix[i];
        };

        const int INF = 1e9;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(k+1, INF))
        );

        for (int i = 0; i < n; i++)
            dp[i][i][1] = 0;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int m = 2; m <= k; m++) {
                    for (int t = i; t < j; t += (k - 1)) {
                        dp[i][j][m] = min(dp[i][j][m],
                            dp[i][t][1] + dp[t+1][j][m-1]);
                    }
                }
                if (dp[i][j][k] < INF)
                    dp[i][j][1] = dp[i][j][k] + sum(i, j);
            }
        }

        return dp[0][n-1][1];
    }
};

