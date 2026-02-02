class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long current_sum = 0;
        long long min_cost = -1;
        
  
        multiset<int> L, R;
        
        
        int target = k - 1;
        
        for (int i = 1; i < nums.size(); ++i) {
         
            L.insert(nums[i]);
            current_sum += nums[i];
            
            
            if (L.size() > target) {
                auto it = prev(L.end()); 
                current_sum -= *it;
                R.insert(*it);
                L.erase(it);
            }
            
            
            if (i > dist + 1) {
                int out_val = nums[i - (dist + 1)];
                auto it_L = L.find(out_val);
                
                if (it_L != L.end()) {
                   
                    L.erase(it_L);
                    current_sum -= out_val;
                    
                 
                    if (!R.empty()) {
                        auto it_R = R.begin();
                        L.insert(*it_R);
                        current_sum += *it_R;
                        R.erase(it_R);
                    }
                } else {
                   
                    auto it_R = R.find(out_val);
                    if (it_R != R.end()) {
                        R.erase(it_R);
                    }
                }
            }
            
         
            if (L.size() == target) {
                if (min_cost == -1 || current_sum < min_cost) {
                    min_cost = current_sum;
                }
            }
        }
        
        
        return nums[0] + min_cost;
    }
};