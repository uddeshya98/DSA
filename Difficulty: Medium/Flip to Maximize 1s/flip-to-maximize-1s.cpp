class Solution {
public:
    int maxOnes(vector<int>& arr) {
        int totalOnes = 0;
        for (int x : arr) {
            if (x == 1) totalOnes++;
        }
        
        int maxGain = 0, curr = 0;
        for (int x : arr) {
            int val = (x == 0) ? 1 : -1;
            curr = max(val, curr + val);
            maxGain = max(maxGain, curr);
        }
        
        return totalOnes + maxGain;
    }
};