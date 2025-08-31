class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = n - 1, ans = 0;
        while (i < j) {
            int h = min(arr[i], arr[j]);
            ans = max(ans, h * (j - i));
            if (arr[i] < arr[j]) i++;
            else j--;
        }
        return ans;
    }
};
