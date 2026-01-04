class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int n : nums) {
            int cnt = 0;
            int sum = 0;

            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    int d1 = i;
                    int d2 = n / i;

                    cnt++;
                    sum += d1;

                    if (d1 != d2) {
                        cnt++;
                        sum += d2;
                    }

                    if (cnt > 4) break;
                }
            }

            if (cnt == 4) {
                totalSum += sum;
            }
        }

        return totalSum;
    }
};
