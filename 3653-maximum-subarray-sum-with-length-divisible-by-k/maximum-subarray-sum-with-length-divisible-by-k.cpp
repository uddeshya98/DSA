class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> bestMin(k, LLONG_MAX);
        
        long long prefix = 0;
        long long ans = LLONG_MIN;
        
        bestMin[0] = 0;  
        
        for(int i = 1; i <= n; i++) {
            prefix += nums[i - 1];
            int rem = i % k;
            
            if(bestMin[rem] != LLONG_MAX) {
                ans = max(ans, prefix - bestMin[rem]);
            }
            
            bestMin[rem] = min(bestMin[rem], prefix);
        }
        
        return ans;
    }
};
