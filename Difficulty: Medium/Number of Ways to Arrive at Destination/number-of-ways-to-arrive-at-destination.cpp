class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        const long long INF = 1e18;
        const int MOD = 1e9+7;

        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(V, INF), ways(V, 0);
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &p : adj[u]){
                int v = p.first;
                long long wt = p.second;
                long long nd = d + wt;

                if(nd < dist[v]){
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.push({nd, v});
                } else if(nd == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[V - 1] % MOD;
    }
};
