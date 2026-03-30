class Solution {
public:
    int minCost(vector<vector<int>>& pts) {
        int n = pts.size(), ans = 0;
        
        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, false);
        
        dist[0] = 0;

        for(int i = 0; i < n; i++) {
            int u = -1;

            for(int j = 0; j < n; j++) {
                if(!vis[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;
            }

            vis[u] = true;
            ans += dist[u];

            for(int v = 0; v < n; v++) {
                if(!vis[v]) {
                    int d = abs(pts[u][0] - pts[v][0]) + abs(pts[u][1] - pts[v][1]);
                    dist[v] = min(dist[v], d);
                }
            }
        }

        return ans;
    }
};