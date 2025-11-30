class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int x : nums) totalSum += x;

        int rem = totalSum % p;
        if (rem == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;  

        long long curr = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            curr = (curr + nums[i]) % p;
            int need = (curr - rem + p) % p;

            if (mp.count(need)) {
                ans = min(ans, i - mp[need]);
            }

            mp[curr] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};
