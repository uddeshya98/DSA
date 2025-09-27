class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> flipped(n, 0);
        int flips = 0, currFlip = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) currFlip ^= flipped[i - k];
            if ((arr[i] ^ currFlip) == 0) {
                if (i + k > n) return -1;
                flips++;
                currFlip ^= 1;
                flipped[i] = 1;
            }
        }
        return flips;
    }
};