class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        auto solve = [](vector<int>& start1, vector<int>& dur1, vector<int>& start2, vector<int>& dur2) {
            int n = start1.size();
            int m = start2.size();
            vector<pair<int, int>> b(m);
            for (int i = 0; i < m; ++i) {
                b[i] = {start2[i], dur2[i]};
            }
            sort(b.begin(), b.end());

            vector<int> pref_dur(m);
            vector<int> suff_fin(m);
            
            pref_dur[0] = b[0].second;
            for (int i = 1; i < m; ++i) {
                pref_dur[i] = min(pref_dur[i - 1], b[i].second);
            }
            
            suff_fin[m - 1] = b[m - 1].first + b[m - 1].second;
            for (int i = m - 2; i >= 0; --i) {
                suff_fin[i] = min(suff_fin[i + 1], b[i].first + b[i].second);
            }

            int res = 2e9;
            vector<int> b_starts(m);
            for (int i = 0; i < m; ++i) {
                b_starts[i] = b[i].first;
            }

            for (int i = 0; i < n; ++i) {
                int t = start1[i] + dur1[i];
                int idx = upper_bound(b_starts.begin(), b_starts.end(), t) - b_starts.begin() - 1;
                
                int cur = 2e9;
                if (idx >= 0) {
                    cur = min(cur, t + pref_dur[idx]);
                }
                if (idx + 1 < m) {
                    cur = min(cur, suff_fin[idx + 1]);
                }
                res = min(res, cur);
            }
            return res;
        };

        return min(solve(landStartTime, landDuration, waterStartTime, waterDuration),
                   solve(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};