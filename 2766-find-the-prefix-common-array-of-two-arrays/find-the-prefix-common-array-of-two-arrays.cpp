class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        vector<int> seen(n + 1, 0);
        int common = 0;

        for (int i = 0; i < n; i++) {
            if (++seen[A[i]] == 2) common++;
            if (++seen[B[i]] == 2) common++;
            ans[i] = common;
        }

        return ans;
    }
};