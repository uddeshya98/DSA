class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for(int q : queries) {
            auto &v = mp[nums[q]];
            
            if(v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();
            
            int next = v[(idx + 1) % v.size()];
            int prev = v[(idx - 1 + v.size()) % v.size()];
            
            int dist1 = min(abs(q - next), n - abs(q - next));
            int dist2 = min(abs(q - prev), n - abs(q - prev));
            
            ans.push_back(min(dist1, dist2));
        }
        
        return ans;
    }
};;