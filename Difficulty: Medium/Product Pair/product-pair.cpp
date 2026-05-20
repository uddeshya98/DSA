class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_map<long long, int> mp;

        for (long long x : arr) {
            if (x == 0) {
                if (target == 0 && arr.size() > 1)
                    return true;
            } else {
                if (target % x == 0) {
                    long long need = target / x;
                    if (mp.count(need))
                        return true;
                }
            }
            mp[x]++;
        }

        return false;
    }
};