class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int totalSum = 0;
        int currMax = 0, maxSum = -1e9 - 7; 
        int currMin = 0, minSum = 1e9 + 7;  

        for (int x : arr) {
            totalSum += x;

            
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);

            
            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);
        }

      
        if (maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};