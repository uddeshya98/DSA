class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = 1e18, ans = r;

        while (l <= r) {
            long long mid = (l + r) / 2;
            long long total = 0;

            for (long long t : workerTimes) {
                long long x = (sqrt(1.0 + (8.0 * mid) / t) - 1) / 2;
                total += x;
                if (total >= mountainHeight) break;
            }

            if (total >= mountainHeight) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};