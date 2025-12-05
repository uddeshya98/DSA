class Solution{
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;
        int k = costs[0].size();
        if(k == 0) return -1;
        if(k == 1) return n == 1 ? costs[0][0] : -1;

        vector<int> dp(k, 0);
        vector<int> newdp(k, 0);

        for(int j = 0; j < k; j++)
            dp[j] = costs[0][j];

        for(int i = 1; i < n; i++){
            int min1 = INT_MAX, min2 = INT_MAX, idx = -1;
            for(int j = 0; j < k; j++){
                if(dp[j] < min1){
                    min2 = min1;
                    min1 = dp[j];
                    idx = j;
                } else if(dp[j] < min2){
                    min2 = dp[j];
                }
            }

            for(int j = 0; j < k; j++){
                if(j == idx) newdp[j] = costs[i][j] + min2;
                else newdp[j] = costs[i][j] + min1;
            }
            dp = newdp;
        }

        int ans = INT_MAX;
        for(int j = 0; j < k; j++)
            ans = min(ans, dp[j]);
        return ans;
    }
};
