class Solution {
public:
    bool canFormPalindrome(string s) {
        vector<int> freq(26, 0);

        for(char c : s) {
            freq[c - 'a']++;
        }

        int odd = 0;

        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 != 0) {
                odd++;
            }
        }

        return odd <= 1;
    }
};