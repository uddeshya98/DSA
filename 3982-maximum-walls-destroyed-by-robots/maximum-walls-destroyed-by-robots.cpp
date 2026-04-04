class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
    
        vector<pair<int, int>> robs(n);
        for (int i = 0; i < n; ++i) {
            robs[i] = {robots[i], distance[i]};
        }
        sort(robs.begin(), robs.end());
        sort(walls.begin(), walls.end());

       
        int base_walls = 0;
        vector<int> W;
        W.reserve(walls.size());
        
        int i = 0, j = 0;
        while (j < walls.size()) {
            while (i < n && robs[i].first < walls[j]) {
                i++;
            }
            if (i < n && robs[i].first == walls[j]) {
                base_walls++;
            } else {
                W.push_back(walls[j]);
            }
            j++;
        }

       
        long long Y0 = robs[0].first;
        long long d0 = robs[0].second;
        auto it_e0 = lower_bound(W.begin(), W.end(), Y0);
        long long l_limit0 = Y0 - d0;
        
        auto it_l0 = lower_bound(W.begin(), it_e0, l_limit0);
        int dp0 = std::distance(it_l0, it_e0); 
        int dp1 = 0; 

        
        for (int k = 0; k < n - 1; ++k) {
            long long X = robs[k].first;
            long long Y = robs[k+1].first;
            long long d_k = robs[k].second;
            long long d_next = robs[k+1].second;

           
            auto it_s = upper_bound(W.begin(), W.end(), X);
            auto it_e = lower_bound(W.begin(), W.end(), Y);

            int l_cov = 0, r_cov = 0, both_cov = 0;
            
            if (it_s < it_e) {
               
                long long r_limit = min((long long)Y - 1, X + d_k);
                long long l_limit = max((long long)X + 1, Y - d_next);

                auto it_r = upper_bound(it_s, it_e, r_limit);
                r_cov = std::distance(it_s, it_r);

                auto it_l = lower_bound(it_s, it_e, l_limit);
                l_cov = std::distance(it_l, it_e);

                
                int intersection = 0;
                if (it_l < it_r) {
                    intersection = std::distance(it_l, it_r);
                }
                both_cov = r_cov + l_cov - intersection;
            }

         
            int next_dp0 = max(dp0 + l_cov, dp1 + both_cov);
            int next_dp1 = max(dp0, dp1 + r_cov);
            
            dp0 = next_dp0;
            dp1 = next_dp1;
        }

        
        long long XN = robs[n-1].first;
        long long dN = robs[n-1].second;
        auto it_sN = upper_bound(W.begin(), W.end(), XN);
        long long r_limitN = XN + dN;
        auto it_rN = upper_bound(it_sN, W.end(), r_limitN);
        int R_covN = std::distance(it_sN, it_rN);

        
        return max(dp0, dp1 + R_covN) + base_walls;
    }
};