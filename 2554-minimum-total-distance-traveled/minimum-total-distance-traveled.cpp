class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
       
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

      
        vector<int> factory_pos;
        for (const auto& f : factory) {
            for (int i = 0; i < f[1]; ++i) {
                factory_pos.push_back(f[0]);
            }
        }

        int n = robot.size();
        int m = factory_pos.size();

    
        vector<long long> dp(m + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
     
            vector<long long> next_dp(m + 1, 1e18); 
            
            for (int j = 1; j <= m; ++j) {
                
                next_dp[j] = next_dp[j - 1];
                
                
                if (dp[j - 1] != 1e18) {
                    long long cost = abs((long long)robot[i - 1] - factory_pos[j - 1]);
                    next_dp[j] = min(next_dp[j], dp[j - 1] + cost);
                }
            }
            dp = next_dp;
        }

        return dp[m];
    }
};