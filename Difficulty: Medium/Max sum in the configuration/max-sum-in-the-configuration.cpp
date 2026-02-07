class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int S = 0;       
        int R0 = 0;      
        
        for (int i = 0; i < n; i++) {
            S += arr[i];
            R0 += i * arr[i];
        }
        
        int ans = R0; 
        int curr = R0;
        

        for (int k = 1; k < n; k++) {
            curr = curr + S - n * arr[n - k];
            ans = max(ans, curr);
        }
        
        return ans;
    }
};
