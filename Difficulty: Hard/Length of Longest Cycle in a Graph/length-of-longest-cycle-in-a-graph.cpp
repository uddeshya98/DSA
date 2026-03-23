class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj(V, -1);
        
        for (auto &e : edges) {
            adj[e[0]] = e[1];
        }
        
        vector<int> vis(V, 0), dist(V, 0);
        int ans = -1;
        
        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;
            
            int node = i;
            int step = 0;
            unordered_map<int, int> mp; 
            
            while (node != -1) {
                if (vis[node]) {
                    if (mp.find(node) != mp.end()) {
                        ans = max(ans, step - mp[node]);
                    }
                    break;
                }
                
                vis[node] = 1;
                mp[node] = step;
                step++;
                
                node = adj[node];
            }
        }
        
        return ans;
    }
};