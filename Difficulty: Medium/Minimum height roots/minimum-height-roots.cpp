class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if (V == 1) return {0};
        
        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) q.push(i);
        }
        
        int remaining = V;
        
        while (remaining > 2) {
            int size = q.size();
            remaining -= size;
            
            while (size--) {
                int node = q.front();
                q.pop();
                
                for (auto &nei : adj[node]) {
                    degree[nei]--;
                    if (degree[nei] == 1) {
                        q.push(nei);
                    }
                }
            }
        }
        
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};