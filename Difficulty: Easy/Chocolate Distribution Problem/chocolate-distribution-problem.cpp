class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        if(m == 0 || n == 0) return 0;
        if(n < m) return -1;
        
        sort(a.begin(), a.end());
        
        int ans = INT_MAX;
        
        for(int i = 0; i + m - 1 < n; i++){
            ans = min(ans, a[i + m - 1] - a[i]);
        }
        
        return ans;
    }
};
