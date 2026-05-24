class Solution {
    int dfs(int i, vector<int>& arr, int d, vector<int>& memo) {
     
        if (memo[i] != 0) {
            return memo[i];
        }
        
        int max_jumps = 1;
        int n = arr.size();
        
        for (int j = i + 1; j <= min(i + d, n - 1) && arr[i] > arr[j]; ++j) {
            max_jumps = max(max_jumps, 1 + dfs(j, arr, d, memo));
        }
        
        for (int j = i - 1; j >= max(i - d, 0) && arr[i] > arr[j]; --j) {
            max_jumps = max(max_jumps, 1 + dfs(j, arr, d, memo));
        }
        

        return memo[i] = max_jumps;
    }
    
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> memo(n, 0);
        int ans = 1;
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i, arr, d, memo));
        }
        
        return ans;
    }
};