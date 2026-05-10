class Solution {
public:
    int maxProfit(int x, int y, vector<int>& a, vector<int>& b) {
        int n = a.size();
        
        vector<int> diff;
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans += b[i];
            diff.push_back(a[i] - b[i]);
        }
        
        sort(diff.begin(), diff.end(), greater<int>());
        
        int take = 0;
        
        for(int d : diff) {
            if(d > 0) take++;
        }
        
        take = min(take, x);
        take = max(take, n - y);
        
        for(int i = 0; i < take; i++) {
            ans += diff[i];
        }
        
        return ans;
    }
};