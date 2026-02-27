class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        
        int count = 0;
        int max_size = min(n, m);
        
        for (int size = 1; size <= max_size; ++size) {
            for (int r1 = 1; r1 <= n - size + 1; ++r1) {
                for (int c1 = 1; c1 <= m - size + 1; ++c1) {
                    int r2 = r1 + size - 1;
                    int c2 = c1 + size - 1;
                    
                    int sum = prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];
                    
                    if (sum == x) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};