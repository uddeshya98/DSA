class Solution {
    struct TrieNode {
        TrieNode* child[2];
        int cnt;
        
        TrieNode() {
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };
    
    TrieNode* root = new TrieNode();
    
   
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 15; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
            node->cnt++;
        }
    }
    
  
    int query(int x, int k) {
        TrieNode* node = root;
        int ans = 0;
        
        for (int i = 15; i >= 0; i--) {
            if (!node) break;
            
            int xBit = (x >> i) & 1;
            int kBit = (k >> i) & 1;
            
            if (kBit == 1) {
               
                if (node->child[xBit])
                    ans += node->child[xBit]->cnt;
                
                node = node->child[1 - xBit];
            } else {
                node = node->child[xBit];
            }
        }
        return ans;
    }

public:
    int cntPairs(vector<int>& arr, int k) {
        int res = 0;
        
        for (int num : arr) {
            res += query(num, k);
            insert(num);
        }
        
        return res;
    }
};
