class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 0, j = nums.size() - 1;
        int maxPairSum = 0;

        while (i < j) {
            int sum = nums[i] + nums[j];
            maxPairSum = max(maxPairSum, sum);
            i++;
            j--;
        }

        return maxPairSum;
    }
};
