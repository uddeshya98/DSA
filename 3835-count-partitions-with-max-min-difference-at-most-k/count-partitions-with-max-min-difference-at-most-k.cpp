class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> dp(n+1), pref(n+1);
        dp[0] = pref[0] = 1;

        deque<int> mx, mn;
        int L = 0;

        for(int i = 0; i < n; i++) {
            while(!mx.empty() && nums[mx.back()] <= nums[i]) mx.pop_back();
            while(!mn.empty() && nums[mn.back()] >= nums[i]) mn.pop_back();
            mx.push_back(i);
            mn.push_back(i);

            while(nums[mx.front()] - nums[mn.front()] > k) {
                if(mx.front() == L) mx.pop_front();
                if(mn.front() == L) mn.pop_front();
                L++;
            }

            if (L == 0)
                dp[i+1] = pref[i];
            else
                dp[i+1] = (pref[i] - pref[L-1] + MOD) % MOD;

            pref[i+1] = (pref[i] + dp[i+1]) % MOD;
        }
        return dp[n];
    }
};
