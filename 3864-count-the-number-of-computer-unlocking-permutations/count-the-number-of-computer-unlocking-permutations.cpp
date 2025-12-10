class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modFact(long long n) {
        long long res = 1;
        for(long long i = 1; i <= n; i++)
            res = (res * i) % MOD;
        return res;
    }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

       
        for(int i = 1; i < n; i++) {
            bool ok = false;
            for(int j = 0; j < i; j++) {
                if (complexity[j] < complexity[i]) {
                    ok = true;
                    break;
                }
            }
            if (!ok) return 0;
        }

       
        return modFact(n - 1);
    }
};
