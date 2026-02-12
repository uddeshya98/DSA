class Solution {
  public:
  
    bool canMake(vector<int> &arr, int k, int w, long long target) {
        int n = arr.size();
        vector<long long> diff(n + 1, 0);
        long long currWater = 0;
        long long usedDays = 0;

        for (int i = 0; i < n; i++) {
            currWater += diff[i];

            long long currentHeight = arr[i] + currWater;

            if (currentHeight < target) {
                long long need = target - currentHeight;
                usedDays += need;

                if (usedDays > k)
                    return false;

                currWater += need;

                if (i + w <= n)
                    diff[i + w] -= need;
            }
        }

        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        long long low = *min_element(arr.begin(), arr.end());
        long long high = low + k;
        long long answer = low;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canMake(arr, k, w, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return answer;
    }
};
