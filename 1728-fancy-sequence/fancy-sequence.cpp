class Fancy {
    const long long MOD = 1e9 + 7;
    vector<long long> seq;
    long long M = 1, A = 0;

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    long long inv(long long x) {
        return power(x, MOD - 2, MOD);
    }

public:
    Fancy() {}

    void append(int val) {
        seq.push_back((val - A % MOD + MOD) % MOD * inv(M) % MOD);
    }

    void addAll(int inc) {
        A = (A + inc) % MOD;
    }

    void multAll(int m) {
        M = M * m % MOD;
        A = A * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (seq[idx] * M % MOD + A) % MOD;
    }
};