class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (auto& q : queries) {
            auto low = lower_bound(arr.begin(), arr.end(), q[0]);
            auto high = upper_bound(arr.begin(), arr.end(), q[1]);
            ans.push_back(high - low);
        }
        return ans;
    }
};