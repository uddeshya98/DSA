class Solution {
public:
    vector<int> diagView(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<int> ans;

       
        for(int sum = 0; sum <= 2*n - 2; sum++) {
            for(int i = 0; i < n; i++) {
                int j = sum - i;

                if(j >= 0 && j < n) {
                    ans.push_back(mat[i][j]);
                }
            }
        }

        return ans;
    }
};