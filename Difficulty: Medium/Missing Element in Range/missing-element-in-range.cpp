class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int> s(arr.begin(), arr.end());
        vector<int> ans;
        for(int i = low; i <= high; i++){
            if(!s.count(i)) ans.push_back(i);
        }
        return ans;
    }
};
