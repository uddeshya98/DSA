class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n == 1) return 0;

        int FULL = (1 << n) - 1;
        const int INF = 1000000000;

        vector<vector<int>> dp(1 << n, vector<int>(n, -1));

        function<int(int,int)> solve = [&](int mask, int u) {
            if (mask == FULL) {
                return cost[u][0];
            }

            int &res = dp[mask][u];
            if (res != -1) return res;

            res = INF;
            for (int v = 0; v < n; v++) {
                if (!(mask & (1 << v))) {
                    res = min(res, cost[u][v] + solve(mask | (1 << v), v));
                }
            }
            return res;
        };

        return solve(1, 0);
    }
};
