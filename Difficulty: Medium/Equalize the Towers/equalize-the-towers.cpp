class Solution {
public:
    long long minCost(vector<int>& h, vector<int>& c) {
        vector<pair<int,int>> v;
        int n = h.size();
        for(int i = 0; i < n; i++) v.push_back({h[i], c[i]});
        sort(v.begin(), v.end());
        
        long long total = 0;
        for(auto &x : v) total += x.second;

        long long pref = 0;
        int target = 0;
        for(int i = 0; i < n; i++){
            pref += v[i].second;
            if(pref * 2 >= total){
                target = v[i].first;
                break;
            }
        }

        long long ans = 0;
        for(int i = 0; i < n; i++)
            ans += 1LL * abs(h[i] - target) * c[i];

        return ans;
    }
};
