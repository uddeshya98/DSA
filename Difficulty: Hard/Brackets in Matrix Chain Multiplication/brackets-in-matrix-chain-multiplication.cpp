class Solution {
public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        int m = n - 1;
        vector<vector<int>> dp(m, vector<int>(m, 0));
        vector<vector<int>> split(m, vector<int>(m, -1));

        for (int l = 2; l <= m; l++) {
            for (int i = 0; i + l - 1 < m; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    long long cost = dp[i][k] + dp[k+1][j] +
                                     1LL * arr[i] * arr[k+1] * arr[j+1];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }
        return build(0, m - 1, split);
    }

    string build(int i, int j, vector<vector<int>>& split) {
        if (i == j) return string(1, 'A' + i);
        int k = split[i][j];
        return "(" + build(i, k, split) + build(k + 1, j, split) + ")";
    }
};
