class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int left = 0, ans = -1;
        unordered_map<char,int> mp;
        
        for(int right = 0; right < s.size(); right++) {
            mp[s[right]]++;
            
            while(mp.size() > k) {
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
            
            if(mp.size() == k) {
                ans = max(ans, right - left + 1);
            }
        }
        
        return ans;
    }
};