class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.rbegin(), x.rend()); 
        sort(y.rbegin(), y.rend());

        int i = 0, j = 0;
        int hz = 1, vl = 1;
        long long cost = 0;

        while (i < x.size() && j < y.size()) {
            if (x[i] >= y[j]) {
                cost += (long long)x[i] * hz;
                vl++;
                i++;
            } else {
                cost += (long long)y[j] * vl;
                hz++;
                j++;
            }
        }

     
        while (i < x.size()) {
            cost += (long long)x[i] * hz;
            vl++;
            i++;
        }

      
        while (j < y.size()) {
            cost += (long long)y[j] * vl;
            hz++;
            j++;
        }

        return (int)cost;
    }
};
