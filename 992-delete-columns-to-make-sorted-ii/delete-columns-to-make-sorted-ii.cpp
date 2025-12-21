class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int deletions = 0;
        
        vector<bool> isSorted(n - 1, false);

        for (int j = 0; j < m; ++j) {
            bool deleteCol = false;
            
            for (int i = 0; i < n - 1; ++i) {
                if (!isSorted[i]) {
                    if (strs[i][j] > strs[i+1][j]) {
                        deleteCol = true;
                        break;
                    }
                }
            }

            if (deleteCol) {
                deletions++;
            } else {
                for (int i = 0; i < n - 1; ++i) {
                    if (!isSorted[i] && strs[i][j] < strs[i+1][j]) {
                        isSorted[i] = true;
                    }
                }
            }
        }
        
        return deletions;
    }
};
