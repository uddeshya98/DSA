class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int total = n * m;
        const int MOD = 12345;
        
        vector<vector<int>> p(n, vector<int>(m));
        
        vector<long long> prefix(total + 1, 1);
        for (int k = 0; k < total; k++) {
            int i = k / m, j = k % m;
            prefix[k + 1] = (prefix[k] * (grid[i][j] % MOD)) % MOD;
        }
        
        vector<long long> suffix(total + 1, 1);
        for (int k = total - 1; k >= 0; k--) {
            int i = k / m, j = k % m;
            suffix[k] = (suffix[k + 1] * (grid[i][j] % MOD)) % MOD;
        }
        
        for (int k = 0; k < total; k++) {
            int i = k / m, j = k % m;
            p[i][j] = (prefix[k] * suffix[k + 1]) % MOD;
        }
        
        return p;
    }
};