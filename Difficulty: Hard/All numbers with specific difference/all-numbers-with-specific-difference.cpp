class Solution {
  public:
    int sumOfDigits(long long n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int getCount(long long n, long long d) {
        long long low = 1, high = n;
        long long first_pos = n + 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid - sumOfDigits(mid) >= d) {
                first_pos = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (first_pos > n) return 0;
        return (n - first_pos + 1);
    }
};