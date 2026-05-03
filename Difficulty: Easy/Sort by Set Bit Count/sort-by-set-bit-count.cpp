class Solution {
public:
    static bool cmp(int a, int b) {
        int c1 = __builtin_popcount(a);
        int c2 = __builtin_popcount(b);
        if (c1 == c2) return false;
        return c1 > c2;
    }

    vector<int> sortBySetBitCount(vector<int>& arr) {
        stable_sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};