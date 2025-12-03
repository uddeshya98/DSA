class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<double, unordered_map<double, int>> cnt1;
        unordered_map<int, unordered_map<double, int>> cnt2;

        cnt1.reserve(n * n);
        cnt2.reserve(n * n);

        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < i; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2 - x1, dy = y2 - y1;
                double k = (dx == 0 ? 1e9 : 1.0 * dy / dx);
                double b = (dx == 0 ? x1 : 1.0 * (1LL * y1 * dx - 1LL * x1 * dy) / dx);

                cnt1[k][b]++;

                int p = (x1 + x2 + 2000) * 4000 + (y1 + y2 + 2000);
                cnt2[p][k]++;
            }
        }

        long long ans = 0;
        for (auto &it : cnt1) {
            auto &mp = it.second;
            long long s = 0;
            for (auto &jt : mp) {
                int t = jt.second;
                ans += s * t;
                s += t;
            }
        }
        for (auto &it : cnt2) {
            auto &mp = it.second;
            long long s = 0;
            for (auto &jt : mp) {
                int t = jt.second;
                ans -= s * t;
                s += t;
            }
        }
        return (int)ans;
    }
};
