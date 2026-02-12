class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int cnt = 0;
                int val = 0;
                bool ok = true;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        if (val == 0) val = freq[k];
                        else if (freq[k] != val) {
                            ok = false;
                            break;
                        }
                        cnt++;
                    }
                }

                if (ok) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
