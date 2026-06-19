class Solution {
public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + arr[i] - arr[i / 2];
        }
        
        return ans;
    }
};