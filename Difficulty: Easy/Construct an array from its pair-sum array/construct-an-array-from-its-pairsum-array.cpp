class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        int m = arr.size();
        
   
        if (m == 1) {
            return {1, arr[0] - 1};
        }
        
       
        int n = (1 + sqrt(1 + 8 * m)) / 2;
        vector<int> res(n);
        
       
        res[0] = (arr[0] + arr[1] - arr[n - 1]) / 2;

        for (int i = 1; i < n; i++) {
            res[i] = arr[i - 1] - res[0];
        }
        
        return res;
    }
};