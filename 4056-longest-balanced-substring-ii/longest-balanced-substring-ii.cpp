class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int max_len = 0;

        int curr_len = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) curr_len++;
            else {
                max_len = max(max_len, curr_len);
                curr_len = 1;
            }
        }
        max_len = max(max_len, curr_len);

        auto solve2 = [&](char c1, char c2) {
            unordered_map<int, int> mp;
            mp[0] = -1;
            int count1 = 0, count2 = 0;
            
            for (int i = 0; i < n; i++) {
                if (s[i] != c1 && s[i] != c2) {
                    mp.clear();
                    mp[0] = i; 
                    count1 = 0; 
                    count2 = 0;
                } else {
                    if (s[i] == c1) count1++;
                    if (s[i] == c2) count2++;
                    
                    int diff = count1 - count2;
                    if (mp.count(diff)) {
                        max_len = max(max_len, i - mp[diff]);
                    } else {
                        mp[diff] = i;
                    }
                }
            }
        };
        
        solve2('a', 'b');
        solve2('b', 'c');
        solve2('a', 'c');

        unordered_map<long long, int> mp3;
        mp3[0] = -1;
        int a = 0, b = 0, c = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;
            
            int diff1 = a - b;
            int diff2 = a - c;
            
            long long key = ((long long)diff1 << 32) | (unsigned int)diff2;
            
            if (mp3.count(key)) {
                max_len = max(max_len, i - mp3[key]);
            } else {
                mp3[key] = i;
            }
        }

        return max_len;
    }
};
