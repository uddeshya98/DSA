class Solution {
public:
    bool solve(int k, string& ans, const string& str2, const vector<vector<int>>& check_at) {
        if (k == ans.length()) return true;
        if (ans[k] != '?') return solve(k + 1, ans, str2, check_at);
        
        for (char c = 'a'; c <= 'z'; ++c) {
            ans[k] = c;
            bool ok = true;
            for (int i : check_at[k]) {
                bool match = true;
                for (int j = 0; j < str2.length(); ++j) {
                    if (ans[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    ok = false;
                    break;
                }
            }
            if (ok && solve(k + 1, ans, str2, check_at)) return true;
        }
        ans[k] = '?';
        return false;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int L = n + m - 1;
        string ans(L, '?');
        
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (ans[i + j] != '?' && ans[i + j] != str2[j]) return "";
                    ans[i + j] = str2[j];
                }
            }
        }
        
        vector<vector<int>> check_at(L);
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                int last = -1;
                for (int j = i + m - 1; j >= i; --j) {
                    if (ans[j] == '?') {
                        last = j;
                        break;
                    }
                }
                if (last == -1) {
                    bool match = true;
                    for (int j = 0; j < m; ++j) {
                        if (ans[i + j] != str2[j]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) return "";
                } else {
                    check_at[last].push_back(i);
                }
            }
        }
        
        if (solve(0, ans, str2, check_at)) return ans;
        return "";
    }
};