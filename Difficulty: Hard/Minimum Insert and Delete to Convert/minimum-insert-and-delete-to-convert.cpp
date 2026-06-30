class Solution {
public:
    int minInsAndDel(vector<int>& a, vector<int>& b) {
        vector<int> lis;
        
        for (int x : a) {
            if (binary_search(b.begin(), b.end(), x)) {
                auto it = lower_bound(lis.begin(), lis.end(), x);
                
                if (it == lis.end()) {
                    lis.push_back(x);
                } else {
                    *it = x;
                }
             }
        }
        
        
        return a.size() + b.size() - 2 * lis.size();
    }
};