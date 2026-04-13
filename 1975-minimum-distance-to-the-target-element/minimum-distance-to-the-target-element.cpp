class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int r = nums.size();
        for(int i = 0; i  < nums.size(); ++i){
            if(nums[i]== target){
                r = min(r,abs(i - start));
            }
        }
        return r;
    }
};