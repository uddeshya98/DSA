class Solution {
private:
  
    int reverseNum(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> latest_index;
        int min_dist = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i) {
         
            if (latest_index.find(nums[i]) != latest_index.end()) {
                min_dist = min(min_dist, i - latest_index[nums[i]]);
            }
            
           
            int rev = reverseNum(nums[i]);
            latest_index[rev] = i;
        }
        
     
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};