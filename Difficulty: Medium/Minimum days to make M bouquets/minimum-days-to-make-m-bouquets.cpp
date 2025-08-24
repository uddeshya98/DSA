class Solution {
  public:
    bool canMake(vector<int>& arr, int k, int m, int day) {
        int bouquets = 0, cnt = 0;
        for (int bloom : arr) {
            if (bloom <= day) {
                cnt++;
                if (cnt == k) {
                    bouquets++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return bouquets >= m;
    }
    
    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long need = 1LL * k * m;
        if (need > arr.size()) return -1;
        
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(arr, k, m, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
