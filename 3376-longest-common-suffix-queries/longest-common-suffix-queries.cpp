class Solution {
    // 1. Ditch the pointers. Use standard integers for indices.
    struct Node {
        int children[26];
        int best_idx;
        
        Node() {
            fill(begin(children), end(children), 0);
            best_idx = -1;
        }
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        
        // 2. Store all nodes in a flat vector. Index 0 is our root.
        vector<Node> trie;
        
        // (Optimization) Pre-allocate memory so the vector never resizes.
        // The max possible nodes is the total sum of characters + 1 (for root).
        int total_len = 0;
        for (const string& w : wordsContainer) total_len += w.length();
        trie.reserve(total_len + 1); 
        
        trie.push_back(Node()); // Initialize root
        
        auto updateBest = [&](int node, int idx) {
            int curr_best = trie[node].best_idx;
            if (curr_best == -1) {
                trie[node].best_idx = idx;
                return;
            }
            int curr_len = wordsContainer[curr_best].length();
            int new_len = wordsContainer[idx].length();
            if (new_len < curr_len || (new_len == curr_len && idx < curr_best)) {
                trie[node].best_idx = idx;
            }
        };
        
        for (int i = 0; i < n; ++i) {
            int curr = 0; // Start at root (index 0)
            updateBest(curr, i);
            for (int j = (int)wordsContainer[i].length() - 1; j >= 0; --j) {
                int c = wordsContainer[i][j] - 'a';
                // If child doesn't exist, create it by appending a new Node
                if (trie[curr].children[c] == 0) {
                    trie[curr].children[c] = trie.size();
                    trie.push_back(Node());
                }
                curr = trie[curr].children[c];
                updateBest(curr, i);
            }
        }
        
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& q : wordsQuery) {
            int curr = 0;
            for (int j = (int)q.length() - 1; j >= 0; --j) {
                int c = q[j] - 'a';
                if (trie[curr].children[c] != 0) {
                    curr = trie[curr].children[c];
                } else {
                    break;
                }
            }
            ans.push_back(trie[curr].best_idx);
        }
        
        return ans;
    }
};