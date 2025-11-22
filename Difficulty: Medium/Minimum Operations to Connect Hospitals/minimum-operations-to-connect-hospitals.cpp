struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n): n(n), p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x ? x : p[x]=find(p[x]); }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if(a==b) return false;
        if(r[a] < r[b]) swap(a,b);
        p[b] = a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};
class Solution {
public:
    int minConnect(int V, vector<vector<int>>& edges) {
        int E = edges.size();
        if(E < V - 1) return -1; 

        DSU dsu(V);
        int unions = 0;
        for(auto &e : edges){
            int u = e[0], v = e[1];
            if(dsu.unite(u, v)) unions++;
        }
       
        int components = V - unions;
        int needed = components - 1; 

        
        int redundant = E - (V - components);

        if(redundant >= needed) return needed;
        return -1;
    }
};