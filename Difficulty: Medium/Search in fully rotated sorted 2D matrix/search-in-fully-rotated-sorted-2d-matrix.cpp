class Solution {
public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0, high = n * m - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;
            int midVal = mat[row][col];
            
            if (midVal == x) return true;
            
         
            int lowRow = low / m, lowCol = low % m;
            int highRow = high / m, highCol = high % m;
            int lowVal = mat[lowRow][lowCol];
            int highVal = mat[highRow][highCol];
            
            if (lowVal <= midVal) { 
                if (lowVal <= x && x < midVal) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (midVal < x && x <= highVal) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return false;
    }
};
