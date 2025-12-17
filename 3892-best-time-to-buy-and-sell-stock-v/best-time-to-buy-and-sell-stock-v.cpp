class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = -4e18;
        vector<long long> flat(k + 1, 0), longp(k + 1, NEG), shortp(k + 1, NEG);

        for (int price : prices) {
            for (int t = k; t >= 0; --t) {
                if (t < k) {
                    flat[t + 1] = max(flat[t + 1], longp[t] + price);
                    flat[t + 1] = max(flat[t + 1], shortp[t] - price);
                }
                longp[t] = max(longp[t], flat[t] - price);
                shortp[t] = max(shortp[t], flat[t] + price);
            }
        }

        long long ans = 0;
        for (int t = 0; t <= k; ++t) ans = max(ans, flat[t]);
        return ans;
    }
};
