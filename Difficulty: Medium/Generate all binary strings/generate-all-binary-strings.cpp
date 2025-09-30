class Solution {
public:
    vector<string> binstr(int n) {
        vector<string> result;
        int total = 1 << n; 
        for (int i = 0; i < total; i++) {
            string s = "";
            for (int j = n - 1; j >= 0; j--) {
                s.push_back(((i >> j) & 1) + '0');
            }
            result.push_back(s);
        }
        return result;
    }
};
