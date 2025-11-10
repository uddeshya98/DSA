class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        vector<int> buy(n, 0), sell(n, 0);
        buy[0] = -arr[0];
        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], (i >= 2 ? sell[i - 2] : 0) - arr[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + arr[i]);
        }
        return sell[n - 1];
    }
};

