class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if (n < 2) return false;
        
        int base_n = n - 1;
        
        for (int i = 0; i < base_n; i++) {
            if (nums[i] != i + 1) return false;
        }
        
        return nums[n - 1] == base_n;
    }
};