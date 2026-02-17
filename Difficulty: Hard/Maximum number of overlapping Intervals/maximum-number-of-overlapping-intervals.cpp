class Solution {
public:
    int overlapInt(vector<vector<int>>& arr) {
        vector<pair<int,int>> events;
        for(auto &it : arr) {
            events.push_back({it[0], 1});
            events.push_back({it[1] + 1, -1});
        }
        sort(events.begin(), events.end());
        int curr = 0, ans = 0;
        for(auto &e : events) {
            curr += e.second;
            ans = max(ans, curr);
        }
        return ans;
    }
};
