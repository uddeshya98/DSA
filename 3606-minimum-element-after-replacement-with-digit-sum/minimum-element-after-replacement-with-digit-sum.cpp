class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for (int x : nums) {
            int s = 0;
            while (x > 0) {
                s += x % 10;
                x /= 10;
            }
            res = min(res, s);
        }
        return res;
    }
};