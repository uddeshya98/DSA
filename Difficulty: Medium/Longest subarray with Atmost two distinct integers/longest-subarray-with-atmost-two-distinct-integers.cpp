class Solution {
public:
    int totalElements(vector<int> &arr) {
        unordered_map<int,int> mp;
        int i = 0, ans = 0;
        for(int j = 0; j < arr.size(); j++) {
            mp[arr[j]]++;
            while(mp.size() > 2) {
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};