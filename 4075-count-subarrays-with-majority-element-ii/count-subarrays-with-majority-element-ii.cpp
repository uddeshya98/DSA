class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> bit(2 * n + 2, 0);
        
        auto add = [&](int idx, int val) {
            for (; idx < bit.size(); idx += idx & -idx) {
                bit[idx] += val;
            }
        };
        
        auto query = [&](int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx) {
                sum += bit[idx];
            }
            return sum;
        };
        
        int offset = n + 1;
        long long ans = 0;
        int curr_sum = 0;
        
        add(curr_sum + offset, 1);
        
        for (int x : nums) {
            curr_sum += (x == target) ? 1 : -1;
            ans += query(curr_sum - 1 + offset);
            add(curr_sum + offset, 1);
        }
        return ans;
    }
};