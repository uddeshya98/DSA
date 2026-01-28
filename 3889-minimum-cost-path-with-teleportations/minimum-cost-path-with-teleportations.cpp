class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        

        vector<vector<vector<int>>> dist(k + 1, vector<vector<int>>(m, vector<int>(n, 1e9)));
        
        dist[0][0][0] = 0;
        
        for (int t = 0; t <= k; ++t) {
            
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[t][i][j] == 1e9) continue;
                    
                    int currentCost = dist[t][i][j];
                    
                    
                    if (j + 1 < n) {
                        dist[t][i][j+1] = min(dist[t][i][j+1], currentCost + grid[i][j+1]);
                    }
                    
                    if (i + 1 < m) {
                        dist[t][i+1][j] = min(dist[t][i+1][j], currentCost + grid[i+1][j]);
                    }
                }
            }
            
            
            if (t < k) {
               
                vector<int> min_cost_for_val(10002, 1e9);
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (dist[t][i][j] != 1e9) {
                            int val = grid[i][j];
                            min_cost_for_val[val] = min(min_cost_for_val[val], dist[t][i][j]);
                        }
                    }
                }
                
                
                int current_min = 1e9;
                for (int v = 10001; v >= 0; --v) {
                    current_min = min(current_min, min_cost_for_val[v]);
                    min_cost_for_val[v] = current_min; // Now this array acts as suffix_min
                }
                
               
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        int dest_val = grid[i][j];
                        int teleport_cost = min_cost_for_val[dest_val];
                        
                        if (teleport_cost != 1e9) {
                            dist[t+1][i][j] = min(dist[t+1][i][j], teleport_cost);
                        }
                    }
                }
            }
        }
        
       
        int ans = 1e9;
        for (int t = 0; t <= k; ++t) {
            ans = min(ans, dist[t][m-1][n-1]);
        }
        
        return ans;
    }
};