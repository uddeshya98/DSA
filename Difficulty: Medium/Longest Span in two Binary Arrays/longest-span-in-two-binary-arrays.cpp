class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int,int> mp;
        int diff = 0, ans = 0;
        mp[0] = -1;
        for(int i = 0; i < n; i++) {
            diff += a1[i] - a2[i];
            if(mp.count(diff)) ans = max(ans, i - mp[diff]);
            else mp[diff] = i;
        }
        return ans;
    }
};