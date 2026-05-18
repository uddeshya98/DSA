class Solution {
public:
    int maxSum(int n) {
        if(n == 0) return 0;
        
        int sum = maxSum(n/2) + maxSum(n/3) + maxSum(n/4);
        
        return max(n, sum);
    }
};