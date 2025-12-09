class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int maxVal = 200000;
        vector<long long> leftCount(maxVal + 1, 0), rightCount(maxVal + 1, 0);
        for (int x : nums) rightCount[x]++;
        long long ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            rightCount[nums[j]]--;
            long long target = nums[j] * 2;
            if (target <= maxVal) ans = (ans + (leftCount[target] * rightCount[target]) % MOD) % MOD;
            leftCount[nums[j]]++;
        }
        return ans;
    }
};
