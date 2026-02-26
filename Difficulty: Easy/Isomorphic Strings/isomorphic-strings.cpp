class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        
        int m1[256] = {0};
        int m2[256] = {0};
        
        for (int i = 0; i < s1.length(); ++i) {
            if (m1[s1[i]] != m2[s2[i]]) {
                return false;
            }
            m1[s1[i]] = i + 1;
            m2[s2[i]] = i + 1;
        }
        
        return true;
    }
};