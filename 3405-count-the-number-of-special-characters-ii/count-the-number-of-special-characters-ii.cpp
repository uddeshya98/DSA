class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> last_lower(26, -1);
        vector<int> first_upper(26, -1);
        
        for (int i = 0; i < word.length(); ++i) {
            if (islower(word[i])) {
                last_lower[word[i] - 'a'] = i;
            } else {
                if (first_upper[word[i] - 'A'] == -1) {
                    first_upper[word[i] - 'A'] = i;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (last_lower[i] != -1 && first_upper[i] != -1 && last_lower[i] < first_upper[i]) {
                count++;
            }
        }
        
        return count;
    }
};