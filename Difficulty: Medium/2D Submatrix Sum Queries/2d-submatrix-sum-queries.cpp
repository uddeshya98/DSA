class Solution {
public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = (int)mat.size();
        int m = (int)mat[0].size();

        vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            long long rowSum = 0;
            for (int j = 1; j <= m; j++) {
                rowSum += mat[i - 1][j - 1];
                pref[i][j] = pref[i - 1][j] + rowSum;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            long long res = pref[r2 + 1][c2 + 1]
                          - pref[r1][c2 + 1]
                          - pref[r2 + 1][c1]
                          + pref[r1][c1];
            ans.push_back((int)res);
        }
        return ans;
    }
};
