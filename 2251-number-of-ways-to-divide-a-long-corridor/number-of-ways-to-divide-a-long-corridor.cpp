class Solution {
public:
    int numberOfWays(std::string corridor) {
        const long long MOD = 1000000007LL;
        std::vector<int> seats;
        seats.reserve(corridor.size());
        for (int i = 0; i < (int)corridor.size(); i++) {
            if (corridor[i] == 'S') seats.push_back(i);
        }
        int m = (int)seats.size();
        if (m == 0 || (m & 1)) return 0;

        long long ans = 1;
        for (int i = 2; i < m; i += 2) {
            long long gap = (long long)seats[i] - seats[i - 1];
            ans = (ans * gap) % MOD;
        }
        return (int)ans;
    }
};
