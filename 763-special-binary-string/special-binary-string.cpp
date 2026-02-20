class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0;
        int i = 0;
        vector<string> substrings;
        
        for (int j = 0; j < s.length(); ++j) {
            count += (s[j] == '1' ? 1 : -1);
            if (count == 0) {
                substrings.push_back("1" + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + "0");
                i = j + 1;
            }
        }
        
        sort(substrings.begin(), substrings.end(), greater<string>());
        
        string result = "";
        for (const string& str : substrings) {
            result += str;
        }
        
        return result;
    }
};