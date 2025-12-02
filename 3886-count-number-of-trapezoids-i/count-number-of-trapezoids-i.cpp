class Solution {
public:
    static const long long MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> mp;

        for (auto &p : points) {
            mp[p[1]]++;
        }

        vector<long long> C2;
        for (auto &it : mp) {
            long long k = it.second;
            if (k >= 2) {
                C2.push_back((k * (k - 1) / 2) % MOD);
            }
        }

        long long sum = 0, sqsum = 0;
        for (long long x : C2) {
            sum = (sum + x) % MOD;
            sqsum = (sqsum + (x * x) % MOD) % MOD;
        }

        long long ans = ((sum * sum) % MOD - sqsum + MOD) % MOD;
        long long inv2 = (MOD + 1) / 2;

        return (ans * inv2) % MOD;
    }
};
