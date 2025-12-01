class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0, high = 0;
        
        for (int b : batteries)
            high += b;
        
        high /= n;   
        
        long long ans = 0;
        
        while (low <= high) {
            long long mid = (low + high) / 2;
            
            long long power = 0;
            for (int b : batteries) {
                power += min((long long)b, mid); 
            }
            
            if (power >= mid * n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
