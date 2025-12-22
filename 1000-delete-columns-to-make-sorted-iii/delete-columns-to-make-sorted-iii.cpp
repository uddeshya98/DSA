class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        vector<int> dp(m, 1);
        int max_kept = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                bool possible = true;
                for (int k = 0; k < n; ++k) {
                    if (strs[k][j] > strs[k][i]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_kept = max(max_kept, dp[i]);
        }
        return m - max_kept;
    }
};