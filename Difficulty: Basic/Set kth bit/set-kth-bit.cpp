class Solution {
  public:
    int setKthBit(int n, int k) {
        int mask = 1 << k;
        int ans = n | mask;
        return ans;
    }
};
