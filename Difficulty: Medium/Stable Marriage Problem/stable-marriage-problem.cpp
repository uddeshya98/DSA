class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        vector<int> partnerW(n, -1), partnerM(n, -1);
        vector<int> next(n, 0);
        vector<vector<int>> rank(n, vector<int>(n));
        
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }
        
        queue<int> freeMen;
        for (int i = 0; i < n; i++) freeMen.push(i);
        
        while (!freeMen.empty()) {
            int m = freeMen.front();
            freeMen.pop();
            
            int w = men[m][next[m]];
            next[m]++;
            
            if (partnerW[w] == -1) {
                partnerW[w] = m;
                partnerM[m] = w;
            } else {
                int m1 = partnerW[w];
                if (rank[w][m] < rank[w][m1]) {
                    partnerW[w] = m;
                    partnerM[m] = w;
                    partnerM[m1] = -1;
                    freeMen.push(m1);
                } else {
                    freeMen.push(m);
                }
            }
        }
        
        return partnerM;
    }
};