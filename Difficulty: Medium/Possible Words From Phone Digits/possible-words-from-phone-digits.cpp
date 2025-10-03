class Solution {
public:
   
    vector<string> possibleWords(vector<int> &a, int N) {
        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> res;
        string cur;
        function<void(int)> dfs = [&](int idx) {
            if (idx == N) {
                if (!cur.empty()) res.push_back(cur);
                return;
            }
            int d = a[idx];
            const string &letters = mapping[d];
            if (letters.empty()) {
                // skip digits 0 and 1
                dfs(idx + 1);
            } else {
                for (char ch : letters) {
                    cur.push_back(ch);
                    dfs(idx + 1);
                    cur.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }


    vector<string> possibleWords(vector<int> &arr) {
        return possibleWords(arr, (int)arr.size());
    }
};
