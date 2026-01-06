class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int currXor = 0;

       
        for (int i = 0; i < k; i++) {
            currXor ^= arr[i];
        }

        int maxXor = currXor;
        for (int i = k; i < n; i++) {
            currXor ^= arr[i - k]; 
            currXor ^= arr[i];     

            maxXor = max(maxXor, currXor);
        }

        return maxXor;
    }
};
