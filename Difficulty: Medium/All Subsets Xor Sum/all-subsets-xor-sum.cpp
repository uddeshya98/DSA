class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        
        for(int bit = 0; bit < 32; bit++) {
            int cnt = 0;
            for(int x : arr) {
                if(x & (1 << bit))
                    cnt++;
            }
            if(cnt > 0) {
                total += (1 << bit) * (1 << (n - 1));
            }
        }
        return total;
    }
};
