class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> lens(n, 0);
        long long cur = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                cur = max(0LL, cur - 1);
            } else if (s[i] == '#') {
                cur *= 2;
            } else if (s[i] == '%') {
                
            } else {
                cur++;
            }
            lens[i] = cur;
        }
        
        if (k >= lens[n - 1]) return '.';
        
        long long curr_k = k;
        for (int i = n - 1; i >= 0; --i) {
            long long prev_len = (i > 0) ? lens[i - 1] : 0;
            
            if (s[i] == '*') {
                continue;
            } else if (s[i] == '#') {
                if (prev_len > 0) {
                    curr_k %= prev_len;
                }
            } else if (s[i] == '%') {
                curr_k = prev_len - 1 - curr_k;
            } else {
                if (curr_k == prev_len) {
                    return s[i];
                }
            }
        }
        
        return '.';
    }
};