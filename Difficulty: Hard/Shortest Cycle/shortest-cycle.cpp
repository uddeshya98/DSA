class Solution {
public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = INT_MAX;
        for (auto &e: edges) {
            int a = e[0], b = e[1];
            vector<int> dist(V, -1);
            queue<int> q;
            dist[a] = 0;
            q.push(a);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v: adj[u]) {
                    if ((u == a && v == b) || (u == b && v == a)) continue;
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            if (dist[b] != -1) ans = min(ans, dist[b] + 1);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};