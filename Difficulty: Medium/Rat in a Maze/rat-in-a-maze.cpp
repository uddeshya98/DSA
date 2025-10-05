class Solution {
  public:
    void dfs(int r, int c, vector<vector<int>>& maze, vector<vector<int>>& vis, int n, string &path, vector<string>& ans) {
        if (r == n-1 && c == n-1) {
            ans.push_back(path);
            return;
        }
        
        int dr[4] = {1, 0, 0, -1};
        int dc[4] = {0, -1, 1, 0};
        char mv[4] = {'D','L','R','U'};
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && maze[nr][nc] == 1 && !vis[nr][nc]) {
                vis[nr][nc] = 1;
                path.push_back(mv[k]);
                dfs(nr, nc, maze, vis, n, path, ans);
                path.pop_back();
                vis[nr][nc] = 0;
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        if (n == 0) return ans;
        if (maze[0][0] == 0 || maze[n-1][n-1] == 0) return ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        string path;
        vis[0][0] = 1;
        dfs(0, 0, maze, vis, n, path, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
