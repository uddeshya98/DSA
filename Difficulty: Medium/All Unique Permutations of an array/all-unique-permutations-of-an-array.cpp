class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        do {
            ans.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        return ans;
    }
};
