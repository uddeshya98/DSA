class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (mat[i][j] == 1) i++;
            else j--;
        }
        int cand = i;
        for (int k = 0; k < n; k++) {
            if (k == cand) continue;
            if (mat[cand][k] == 1 || mat[k][cand] == 0) return -1;
        }
        return cand;
    }
};
