class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> cat = {1, 1, 2, 5, 14, 42, 132};
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            int left = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] < arr[i]) {
                    left++;
                }
            }
            int right = n - 1 - left;
            ans.push_back(cat[left] * cat[right]);
        }
        
        return ans;
    }
};