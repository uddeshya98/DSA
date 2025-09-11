class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        if (arr[0] == 0) return -1;

        int jumps = 0, farthest = 0, end = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + arr[i]);
            if (i == end) {
                jumps++;
                end = farthest;
                if (end >= n - 1) return jumps;
            }
            if (farthest <= i) return -1;
        }
        return -1;
    }
};
