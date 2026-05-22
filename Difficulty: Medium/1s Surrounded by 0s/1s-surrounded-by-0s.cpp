class Solution {
public:
    int cntOnes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) {
                q.push({i, 0});
                visited[i][0] = true;
            }
            if(grid[i][m-1] == 1) {
                q.push({i, m-1});
                visited[i][m-1] = true;
            }
        }
        
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1 && !visited[0][j]) {
                q.push({0, j});
                visited[0][j] = true;
            }
            if(grid[n-1][j] == 1 && !visited[n-1][j]) {
                q.push({n-1, j});
                visited[n-1][j] = true;
            }
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};