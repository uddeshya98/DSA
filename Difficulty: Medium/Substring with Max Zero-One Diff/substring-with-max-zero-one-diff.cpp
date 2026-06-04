class Solution {
public:
    int maxSubstring(string &s) {
        int max_diff = -1;
        int current_diff = 0;
        
        for (char c : s) {
            current_diff += (c == '0') ? 1 : -1;
            max_diff = max(max_diff, current_diff);
            if (current_diff < 0) {
                current_diff = 0;
            }
        }
        
        return max_diff;
    }
};