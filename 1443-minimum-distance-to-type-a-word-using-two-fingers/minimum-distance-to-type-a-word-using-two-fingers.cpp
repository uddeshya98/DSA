class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<int>> dp(27, vector<int>(27, 1e9));
        dp[26][26] = 0;

        for (char c : word) {
            int cur = c - 'A';
            vector<vector<int>> ndp(27, vector<int>(27, 1e9));
            for (int i = 0; i <= 26; i++) {
                for (int j = 0; j <= 26; j++) {
                    if (dp[i][j] == 1e9) continue;
                    ndp[cur][j] = min(ndp[cur][j], dp[i][j] + dist(i == 26 ? -1 : i, cur));
                    ndp[i][cur] = min(ndp[i][cur], dp[i][j] + dist(j == 26 ? -1 : j, cur));
                }
            }
            dp = ndp;
        }

        int ans = 1e9;
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};