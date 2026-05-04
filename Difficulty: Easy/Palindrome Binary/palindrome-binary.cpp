class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        int rev = 0;
        int temp = n;
        
        while (temp > 0) {
            rev = (rev << 1) | (temp & 1);
            temp = temp >> 1;
        }
        
        return rev == n;
    }
};