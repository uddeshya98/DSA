class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++)
            if (pat[i - 1] == '*') dp[i][0] = dp[i - 1][0];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (pat[i - 1] == txt[j - 1] || pat[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (pat[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};
