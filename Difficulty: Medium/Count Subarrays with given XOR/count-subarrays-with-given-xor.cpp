class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int,int> mp;
        long count = 0;
        int xr = 0;
        
        for (int num : arr) {
            xr ^= num;
            if (xr == k) count++;
            if (mp.count(xr ^ k)) count += mp[xr ^ k];
            mp[xr]++;
        }
        return count;
    }
};