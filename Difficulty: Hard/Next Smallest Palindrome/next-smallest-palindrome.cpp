class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        bool all_nine = true;
        for (int i = 0; i < n; i++) {
            if (num[i] != 9) {
                all_nine = false;
                break;
            }
        }
        
        if (all_nine) {
            vector<int> ans(n + 1, 0);
            ans[0] = 1;
            ans[n] = 1;
            return ans;
        }
        
        vector<int> ans = num;
        int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2 == 0) ? mid : mid + 1;
        
        while (i >= 0 && ans[i] == ans[j]) {
            i--;
            j++;
        }
        
        bool increment = false;
        if (i < 0 || ans[i] < ans[j]) {
            increment = true;
        }
        
        int left = mid - 1;
        int right = (n % 2 == 0) ? mid : mid + 1;
        while (left >= 0) {
            ans[right] = ans[left];
            left--;
            right++;
        }
        
        if (increment) {
            int carry = 1;
            int pos = (n % 2 != 0) ? mid : mid - 1;
            while (pos >= 0 && carry > 0) {
                ans[pos] += carry;
                carry = ans[pos] / 10;
                ans[pos] %= 10;
                pos--;
            }
            
            left = mid - 1;
            right = (n % 2 == 0) ? mid : mid + 1;
            while (left >= 0) {
                ans[right] = ans[left];
                left--;
                right++;
            }
        }
        
        return ans;
    }
};