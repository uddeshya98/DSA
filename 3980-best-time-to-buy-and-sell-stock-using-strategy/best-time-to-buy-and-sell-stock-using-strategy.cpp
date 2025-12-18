class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long base = 0;
        for (int i = 0; i < n; i++) base += 1LL * strategy[i] * prices[i];
        
        int h = k / 2;
        vector<long long> prefA(n + 1, 0), prefB(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefA[i + 1] = prefA[i] + (-1LL * strategy[i] * prices[i]);
            prefB[i + 1] = prefB[i] + (1LL * (1 - strategy[i]) * prices[i]);
        }
        
        long long best = 0;
        for (int l = 0; l + k <= n; l++) {
            long long delta1 = prefA[l + h] - prefA[l];
            long long delta2 = prefB[l + k] - prefB[l + h];
            best = max(best, delta1 + delta2);
        }
        
        return base + best;
    }
};
