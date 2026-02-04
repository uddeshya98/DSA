class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long inf = 1e16; 
        long long inc1 = -inf;
        long long dec = -inf;
        long long inc2 = -inf;
        long long ans = -inf;
        
        int n = nums.size();
        
        for (int i = 1; i < n; ++i) {
            long long curr = nums[i];
            long long prev = nums[i-1];
            
            long long n_inc1 = -inf;
            long long n_dec = -inf;
            long long n_inc2 = -inf;
            
            if (curr > prev) {
                n_inc1 = prev + curr;
                if (inc1 != -inf) {
                    n_inc1 = max(n_inc1, inc1 + curr);
                }
                
                if (dec != -inf) {
                    n_inc2 = max(n_inc2, dec + curr);
                }
                if (inc2 != -inf) {
                    n_inc2 = max(n_inc2, inc2 + curr);
                }
            } else if (curr < prev) {
                if (inc1 != -inf) {
                    n_dec = max(n_dec, inc1 + curr);
                }
                if (dec != -inf) {
                    n_dec = max(n_dec, dec + curr);
                }
            }
            
            inc1 = n_inc1;
            dec = n_dec;
            inc2 = n_inc2;
            
            if (inc2 != -inf) {
                if (ans == -inf || inc2 > ans) {
                    ans = inc2;
                }
            }
        }
        
        return ans;
    }
};