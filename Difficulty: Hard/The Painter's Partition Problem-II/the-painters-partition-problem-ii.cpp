class Solution {
  public:
    bool check(vector<int>& arr, int k, int timeLimit) {
        int painters = 1;
        int currentBoardSum = 0;
        
        for (int len : arr) {
            if (currentBoardSum + len > timeLimit) {
                painters++;
                currentBoardSum = len;
            } else {
                currentBoardSum += len;
            }
        }
        return painters <= k;
    }

    int minTime(vector<int>& arr, int k) {
        int low = 0;
        int high = 0;
        
        for (int x : arr) {
            if (x > low) low = x;
            high += x;
        }
        
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (check(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};