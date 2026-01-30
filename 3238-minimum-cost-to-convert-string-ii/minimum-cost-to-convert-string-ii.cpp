class Solution {
    struct TrieNode {
        TrieNode* children[26];
        int id; 
        TrieNode() {
            id = -1;
            fill(begin(children), end(children), nullptr);
        }
    };

    void insert(TrieNode* root, const string& s, int id) {
        TrieNode* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->id = id;
    }

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.length();
        
        
        TrieNode* root = new TrieNode();
        int idCounter = 0;
        
        auto getOrInsert = [&](const string& s) {
            TrieNode* node = root;
            for (char c : s) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            if (node->id == -1) {
                node->id = idCounter++;
            }
            return node->id;
        };

        
        for (const string& s : original) getOrInsert(s);
        for (const string& s : changed) getOrInsert(s);

       
        int k = idCounter;
        const long long INF = 1e15; 
        vector<vector<long long>> dist(k, vector<long long>(k, INF));

        for (int i = 0; i < k; ++i) dist[i][i] = 0;

        for (size_t i = 0; i < original.size(); ++i) {
            int u = getOrInsert(original[i]);
            int v = getOrInsert(changed[i]);
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        
        for (int m = 0; m < k; ++m) {
            for (int u = 0; u < k; ++u) {
                if (dist[u][m] == INF) continue;
                for (int v = 0; v < k; ++v) {
                    if (dist[m][v] == INF) continue;
                    dist[u][v] = min(dist[u][v], dist[u][m] + dist[m][v]);
                }
            }
        }

       
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INF) continue;

            
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

           
            TrieNode* nodeS = root;
            TrieNode* nodeT = root;
            
            for (int len = 0; i + len < n; ++len) {
                int charS = source[i + len] - 'a';
                int charT = target[i + len] - 'a';

                
                if (!nodeS->children[charS] || !nodeT->children[charT]) break;
                
                nodeS = nodeS->children[charS];
                nodeT = nodeT->children[charT];

               
                if (nodeS->id != -1 && nodeT->id != -1) {
                    int u = nodeS->id;
                    int v = nodeT->id;
                    if (dist[u][v] < INF) {
                        dp[i + len + 1] = min(dp[i + len + 1], dp[i] + dist[u][v]);
                    }
                }
            }
        }

        return (dp[n] == INF) ? -1 : dp[n];
    }
};