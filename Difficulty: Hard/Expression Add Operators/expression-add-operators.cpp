class Solution {
public:
    vector<string> findExpr(string &s, int target) {
        vector<string> ans;
        string path;
        dfs(s, target, 0, 0LL, 0LL, path, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }

private:
   
    void dfs(const string &s, int target, int idx, long long curVal, long long last,
             string &path, vector<string> &ans) {
        int n = s.size();
        if (idx == n) {
            if (curVal == target) ans.push_back(path);
            return;
        }

    
        long long num = 0;
        int startLen = path.size();
        for (int j = idx; j < n; ++j) {
           
            if (j > idx && s[idx] == '0') break;

            num = num * 10 + (s[j] - '0');
            string numStr = s.substr(idx, j - idx + 1);

            if (idx == 0) {
                
                
                path += numStr;
                dfs(s, target, j + 1, num, num, path, ans);
                path.resize(startLen);
            } else {
            
            
                path += '+'; path += numStr;
                dfs(s, target, j + 1, curVal + num, num, path, ans);
                path.resize(startLen);

              
                path += '-'; path += numStr;
                dfs(s, target, j + 1, curVal - num, -num, path, ans);
                path.resize(startLen);

            
                path += '*'; path += numStr;
              
                dfs(s, target, j + 1, curVal - last + last * num, last * num, path, ans);
                path.resize(startLen);
            }
        }
    }
};