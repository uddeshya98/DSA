class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    int solve(int fromCap, int toCap, int d) {
        int from = 0, to = 0, step = 0;
        while (from != d && to != d) {
            if (from == 0) {
                from = fromCap;
                step++;
            } else if (to == toCap) {
                to = 0;
                step++;
            } else {
                int temp = min(from, toCap - to);
                to += temp;
                from -= temp;
                step++;
            }
        }
        return step;
    }
    
    int minSteps(int m, int n, int d) {
        if (d > max(m, n)) return -1;
        if (d % gcd(m, n) != 0) return -1;
        return min(solve(m, n, d), solve(n, m, d));
    }
};