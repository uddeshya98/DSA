class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        int sum = 0;
        for (int x : arr) sum += x;
        
        if ((sum + target) % 2 != 0 || abs(target) > sum) return 0;
        
        int s1 = (sum + target) / 2;
        vector<int> dp(s1 + 1, 0);
        dp[0] = 1;
        
        for (int x : arr) {
            for (int j = s1; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }
        
        return dp[s1];
    }
};