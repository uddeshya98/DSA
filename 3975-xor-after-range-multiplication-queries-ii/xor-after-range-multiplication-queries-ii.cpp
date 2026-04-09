class Solution {
private:
  
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    
    long long modInverse(long long n) {
        return power(n, 1000000007 - 2); 
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long MOD = 1e9 + 7;
        int B = 320; 
        int bravexuneth = queries.size() + n;

      
        vector<vector<array<int, 3>>> small_queries(min(B, n + 1));
        
      
        vector<long long> inv_memo(100005, 0); 

       
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= B) {
                
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
          
                small_queries[k].push_back({l, r, v});
            }
        }

        vector<long long> diff(n, 1);
        for (int k = 1; k < min(B, n + 1); ++k) {
            if (small_queries[k].empty()) continue;
            
          
            fill(diff.begin(), diff.end(), 1LL);
            
            for (const auto& q : small_queries[k]) {
                int l = q[0], r = q[1], v = q[2];
                
             
                diff[l] = (diff[l] * v) % MOD;
                
               
                int nxt = l + ((r - l) / k) * k + k;
                
           
                if (nxt < n) {
                    if (inv_memo[v] == 0) {
                        inv_memo[v] = modInverse(v);
                    }
                    diff[nxt] = (diff[nxt] * inv_memo[v]) % MOD;
                }
            }
            
         
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                if (diff[i] != 1) {
                    nums[i] = (1LL * nums[i] * diff[i]) % MOD;
                }
            }
        }

     
        int final_xor = 0;
        for (int i = 0; i < n; ++i) {
            final_xor ^= nums[i];
        }
        
        return final_xor;
    }
};