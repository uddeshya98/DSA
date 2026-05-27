class Solution {
public:
    bool wifiRange(string &s, int x) {
        int covered = -1;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i - x > covered + 1) {
                    return false;
                }
                if (i + x > covered) {
                    covered = i + x;
                }
            }
        }
        
        return covered >= n - 1;
    }
};