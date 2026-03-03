class Solution {
public:
    char findKthBit(int n, int k) {
        int len = (1 << n) - 1;
        if(n == 1) return '0';
        int mid = len / 2 + 1;
        if(k == mid) return '1';
        if(k < mid) return findKthBit(n - 1, k);
        char bit = findKthBit(n - 1, mid - (k - mid));
        return bit == '0' ? '1' : '0';
    }
};