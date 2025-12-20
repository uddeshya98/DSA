class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int l = 0, r = arr.size();
        while(l < r) {
            int m = l + (r - l) / 2;
            if(arr[m] < k) l = m + 1;
            else r = m;
        }
        return l;
    }
};
