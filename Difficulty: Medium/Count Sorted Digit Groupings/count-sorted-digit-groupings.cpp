class Solution {
public:
    int validGroups(string &s) {
        int n = s.size();
   
        map<pair<int,int>, int> memo;
        
        function<int(int, int)> solve = [&](int idx, int lastSum) -> int {
            if (idx == n) return 1; 
            
            auto key = make_pair(idx, lastSum);
            if (memo.count(key)) return memo[key];
            
            int res = 0;
            int curSum = 0;
            
            for (int end = idx; end < n; end++) {
                curSum += (s[end] - '0');
                if (curSum >= lastSum) {
                    res += solve(end + 1, curSum);
                }
            }
            
            return memo[key] = res;
        };
        
        return solve(0, 0); 
    }
};