class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(string bottom) {
        if (bottom.size() == 1) return true;
        if (memo.count(bottom)) return memo[bottom];

        vector<string> nextLevels;
        string curr = "";
        buildNext(bottom, 0, curr, nextLevels);

        for (string &next : nextLevels) {
            if (dfs(next)) return memo[bottom] = true;
        }
        return memo[bottom] = false;
    }

    void buildNext(string &bottom, int idx, string &curr, vector<string> &res) {
        if (idx == bottom.size() - 1) {
            res.push_back(curr);
            return;
        }

        string key = bottom.substr(idx, 2);
        if (!mp.count(key)) return;

        for (char ch : mp[key]) {
            curr.push_back(ch);
            buildNext(bottom, idx + 1, curr, res);
            curr.pop_back();
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
