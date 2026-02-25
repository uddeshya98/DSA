 class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            int c1 = __builtin_popcount(a);
            int c2 = __builtin_popcount(b);
            if(c1 == c2) return a < b;
            return c1 < c2;
        });
        return arr;
    }
};