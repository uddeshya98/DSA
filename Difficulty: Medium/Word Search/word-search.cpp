class Solution {
public:

    bool dfs(vector<vector<char>>& mat, int i, int j, string &word, int idx) {
       
        if(idx == word.size()) return true;

       
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] != word[idx])
            return false;

        
        char temp = mat[i][j];
        mat[i][j] = '#';

      
        bool found =
            dfs(mat, i+1, j, word, idx+1) ||
            dfs(mat, i-1, j, word, idx+1) ||
            dfs(mat, i, j+1, word, idx+1) ||
            dfs(mat, i, j-1, word, idx+1);

      
        mat[i][j] = temp;

        return found;
    }

    bool isWordExist(vector<vector<char>> &mat, string &word) {

        int n = mat.size();
        int m = mat[0].size();

      
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == word[0]) {
                    if(dfs(mat, i, j, word, 0)) return true;
                }
            }
        }

        return false;
    }
};
