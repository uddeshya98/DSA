class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double total = 0;
        long double low = 1e18, high = -1e18;

        for (auto &s : squares) {
            long double y = s[1], l = s[2];
            total += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        long double half = total / 2.0;

        for (int it = 0; it < 80; it++) {
            long double mid = (low + high) / 2.0;
            long double below = 0;

            for (auto &s : squares) {
                long double y = s[1], l = s[2];
                if (mid <= y) continue;
                if (mid >= y + l) below += l * l;
                else below += (mid - y) * l;
            }

            if (below < half) low = mid;
            else high = mid;
        }

        return (double)low;
    }
};
