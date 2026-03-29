class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = 0;
        for(int x : arr) sum += x;
        
        if((sum + diff) % 2 != 0 || sum < diff) return 0;
        
        int target = (sum + diff) / 2;
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int num : arr) {
            for(int j = target; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[target];
    }
};