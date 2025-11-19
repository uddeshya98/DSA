class Solution {
  public:
    bool checkKthBit(int n, int k) {
        int mask = 1 << k;
        int ans = n;
        return( n & mask ) != 0;
      
        
    }
    
};