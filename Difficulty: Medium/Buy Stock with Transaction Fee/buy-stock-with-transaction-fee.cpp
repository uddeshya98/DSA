class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        
        int buy = -arr[0];
        int sell = 0;        
        
        for(int i = 1; i < n; i++) {
            buy = max(buy, sell - arr[i]);
            sell = max(sell, buy + arr[i] - k);
        }
        
        return sell;
    }
};