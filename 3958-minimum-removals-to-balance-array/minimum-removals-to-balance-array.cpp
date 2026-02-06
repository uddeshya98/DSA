class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), j = 0, ans = n - 1;
        for (int i = 0; i < n; i++) {
            while (j < n && (long long)nums[j] <= (long long)nums[i] * k) j++;
            ans = min(ans, i + (n - j));
        }
        return ans;
    }
};
