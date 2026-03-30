class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int count[2][26] = {0};
        int n = s1.length();
        
        for (int i = 0; i < n; ++i) {
            count[i % 2][s1[i] - 'a']++;
            count[i % 2][s2[i] - 'a']--;
        }
        
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (count[i][j] != 0) {
                    return false;
                }
            }
        }
        
        return true;
    }
};