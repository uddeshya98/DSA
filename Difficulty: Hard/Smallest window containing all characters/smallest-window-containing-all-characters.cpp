class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        if (p.size() > s.size()) return "";

        vector<int> freqP(26, 0), freqS(26, 0);
        for (char c : p) freqP[c - 'a']++;

        int required = p.size();
        int formed = 0;
        int left = 0, minLen = INT_MAX, start = -1;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            freqS[c - 'a']++;

            if (freqP[c - 'a'] > 0 && freqS[c - 'a'] <= freqP[c - 'a']) {
                formed++;
            }

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                freqS[leftChar - 'a']--;
                if (freqP[leftChar - 'a'] > 0 && freqS[leftChar - 'a'] < freqP[leftChar - 'a']) {
                    formed--;
                }
                left++;
            }
        }

        if (start == -1) return "";
        return s.substr(start, minLen);
    }
};
