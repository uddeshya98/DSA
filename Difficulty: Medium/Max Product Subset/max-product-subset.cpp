class Solution {
public:
    int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        long long MOD = 1e9 + 7;
        long long product = 1;
        int max_neg = INT_MIN;
        int count_neg = 0, count_zero = 0;
        bool has_pos = false;

        for (int x : arr) {
            if (x == 0) {
                count_zero++;
                continue;
            }
            if (x < 0) {
                count_neg++;
                max_neg = max(max_neg, x);
            } else {
                has_pos = true;
            }
            product = (product * x) % MOD;
        }

        if (count_zero == n || (count_neg == 1 && count_zero + count_neg == n)) {
            return 0;
        }

        if (count_neg % 2 != 0) {
            product /= max_neg;
        }

        return (int)((product + MOD) % MOD);
    }
};