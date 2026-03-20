class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        
        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                vector<int> vals;
                
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        vals.push_back(grid[r][c]);
                    }
                }
                
                sort(vals.begin(), vals.end());
                vals.erase(unique(vals.begin(), vals.end()), vals.end());
                
                if (vals.size() <= 1) {
                    ans[i][j] = 0;
                } else {
                    int min_d = 2e9; 
                    for (size_t v = 1; v < vals.size(); ++v) {
                        min_d = min(min_d, vals[v] - vals[v - 1]);
                    }
                    ans[i][j] = min_d;
                }
            }
        }
        
        return ans;
    }
};