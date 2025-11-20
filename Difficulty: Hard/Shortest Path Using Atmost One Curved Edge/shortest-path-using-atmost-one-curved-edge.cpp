class Solution {
  public:

    const long long INF = 1e18;

    vector<long long> dijkstra(int start, int V, vector<vector<pair<int,int>>> &adj) {
        vector<long long> dist(V, INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if(d != dist[node]) continue;

            for(auto &p : adj[node]) {
                int nbr = p.first;
                long long w = p.second;

                if(dist[nbr] > d + w) {
                    dist[nbr] = d + w;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return dist;
    }

    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        
        vector<vector<pair<int,int>>> adj(V);

        for(auto &e : edges) {
            int x = e[0], y = e[1], w1 = e[2];
            adj[x].push_back({y, w1});
            adj[y].push_back({x, w1});
        }

        vector<long long> distA = dijkstra(a, V, adj);
        vector<long long> distB = dijkstra(b, V, adj);

        long long ans = distA[b];

        for(auto &e : edges) {
            int x = e[0], y = e[1], w2 = e[3];
            ans = min(ans, distA[x] + (long long)w2 + distB[y]);
            ans = min(ans, distA[y] + (long long)w2 + distB[x]);
        }

        if(ans >= INF/2) return -1;
        return (int)ans;
    }
};
