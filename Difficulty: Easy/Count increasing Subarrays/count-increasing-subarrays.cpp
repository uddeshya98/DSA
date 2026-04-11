class Solution {
public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        long long count = 0;
        int len = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                len++;
            } else {
                count += (long long)(len * (len - 1)) / 2;
                len = 1;
            }
        }

        count += (long long)(len * (len - 1)) / 2;
        return count;
    }
};