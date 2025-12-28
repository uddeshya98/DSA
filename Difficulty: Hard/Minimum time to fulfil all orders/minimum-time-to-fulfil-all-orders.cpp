class Solution {
  public:
    bool isPossible(int n, vector<int>& ranks, int time) {
        int donutsMade = 0;
        for (int r : ranks) {
           
            int k = (-1 + sqrt(1 + 8.0 * time / r)) / 2;
            
            donutsMade += k;
            if (donutsMade >= n) return true; 
        }
        return donutsMade >= n;
    }

    int minTime(vector<int>& ranks, int n) {
        int low = 0;
        
        int high = 1e8; 
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(n, ranks, mid)) {
                ans = mid;    
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }
        return ans;
    }
};