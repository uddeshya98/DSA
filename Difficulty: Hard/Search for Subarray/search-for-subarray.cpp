class Solution {
public:
    vector<int> search(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> result;
        
        if (m == 0 || n < m) {
            return result;
        }
        
        
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (b[i] == b[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
    
        i = 0; 
        int j = 0; 
        while (i < n) {
            if (b[j] == a[i]) {
                j++;
                i++;
            }
            
            if (j == m) {
             
                result.push_back(i - j);
                j = lps[j - 1]; 
            } else if (i < n && b[j] != a[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return result;
    }
};