class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1 << k;
        if (s.size() < k + need - 1) return false;

        unordered_set<int> st;
        int hash = 0, mask = need - 1;

        for (int i = 0; i < s.size(); i++) {
            hash = ((hash << 1) & mask) | (s[i] - '0');
            if (i >= k - 1) {
                st.insert(hash);
                if (st.size() == need) return true;
            }
        }
        return false;
    }
};