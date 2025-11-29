class Solution {
public:
    int countSetBits(int n) {
        int total = 0;
        
        for (int i = 0; (1 << i) <= n; i++) {
            int blockSize = 1 << (i + 1);
            int fullBlocks = (n + 1) / blockSize;
            
            total += fullBlocks * (blockSize / 2);
            
            int remaining = (n + 1) % blockSize;
            total += max(0, remaining - (blockSize / 2));
        }
        
        return total;
    }
};
