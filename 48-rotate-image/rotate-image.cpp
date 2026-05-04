class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < row; col++) {
                swap(matrix[col][row], matrix[row][col]);
            }
        }

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n / 2; col++) {
                swap(matrix[row][col], matrix[row][n - 1 - col]);
            }
        }
    }
};