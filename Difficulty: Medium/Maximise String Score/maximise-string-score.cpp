class Solution {
  public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();
        if (n == 0) return 0;

        int id[256];
        std::fill(id, id + 256, -1);
        std::vector<char> rev;
        int K = 0;

        for (char ch : s) {
            unsigned char uc = (unsigned char)ch;
            if (id[uc] == -1) {
                id[uc] = K++;
                rev.push_back(ch);
            }
        }

        for (auto &v : jumps) {
            if (v.size() < 2) continue;
            for (char ch : v) {
                unsigned char uc = (unsigned char)ch;
                if (id[uc] == -1) {
                    id[uc] = K++;
                    rev.push_back(ch);
                }
            }
        }

        int M = K;
        std::vector<int> ascii(M);
        for (int i = 0; i < M; ++i) ascii[i] = (unsigned char)rev[i];

        std::vector<std::vector<char>> allow(M, std::vector<char>(M, 0));
        for (auto &v : jumps) {
            if (v.size() < 2) continue;
            unsigned char ua = (unsigned char)v[0];
            unsigned char ub = (unsigned char)v[1];
            int a = id[ua];
            int b = id[ub];
            allow[a][b] = 1;
        }

        std::vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (unsigned char)s[i];
        }

        std::vector<int> total(M, 0);
        for (char ch : s) {
            total[id[(unsigned char)ch]]++;
        }

        const long long NEG = (long long)-4e18;
        std::vector<long long> best(M, NEG);
        std::vector<long long> dp(n + 1, 0);
        std::vector<int> suffix(M, 0);

        for (int i = n - 1; i >= 0; --i) {
            int ai = id[(unsigned char)s[i]];
            long long bestdp = 0;

            for (int t = 0; t < M; ++t) {
                if (t == ai || allow[ai][t]) {
                    if (best[t] == NEG) continue;
                    int cnt_i_t = total[t] - suffix[t] - (t == ai ? 1 : 0);
                    long long cand = -pre[i] + 1LL * ascii[t] * cnt_i_t + best[t];
                    if (cand > bestdp) bestdp = cand;
                }
            }

            dp[i] = bestdp;

            int cntAi_i = total[ai] - suffix[ai] - 1;
            long long F = pre[i] - 1LL * (unsigned char)s[i] * cntAi_i + dp[i];
            if (F > best[ai]) best[ai] = F;

            suffix[ai]++;
        }

        return (int)dp[0];
    }
};
