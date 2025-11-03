class Solution {
private:
    
    bool isSafe(int u, const vector<vector<int>>& adj, vector<int>& state) {

        if (state[u] == 1) {
            return false;
        }
        
        
        if (state[u] == 2) {
            return true;
        }

        
        state[u] = 1;

 
        for (int v : adj[u]) {
            
            if (!isSafe(v, adj, state)) {
                return false; 
            }
        }

       
        state[u] = 2;
        return true;
    }

public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
    
        vector<vector<int>> adj(V);
        for (const auto& edge : edges) {
            
            adj[edge[0]].push_back(edge[1]);
        }

      
        vector<int> state(V, 0);

      
        for (int i = 0; i < V; ++i) {
         
            if (state[i] == 0) {
                isSafe(i, adj, state);
            }
        }


        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (state[i] == 2) {
                result.push_back(i);
            }
        }
        
       
        return result;
    }
};