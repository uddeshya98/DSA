class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 0) return "";
        
        int n = encodedText.size();
        int cols = n / rows;
        
        vector<vector<char>> mat(rows, vector<char>(cols));
        
       
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[idx++];
            }
        }
        
        string result = "";
        
    
        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;
            while (i < rows && j < cols) {
                result += mat[i][j];
                i++;
                j++;
            }
        }
        
        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};