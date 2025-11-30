class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        TrieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };
    
    int countSubs(string& s) {
        TrieNode* root = new TrieNode();
        int count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            TrieNode* curr = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (curr->child[idx] == nullptr) {
                    curr->child[idx] = new TrieNode();
                    count++;   // new substring found
                }
                curr = curr->child[idx];
            }
        }

        return count;
    }
};
