class Solution {
  public:
    vector<string> generateBinary(int n) {
        vector<string> result;
        result.reserve(n);  

        for (int i = 1; i <= n; i++) {
            result.push_back(toBinary(i));
        }
        return result;
    }

  private:
    string toBinary(int num) {
        string s = "";
        while (num > 0) {
            s.push_back((num % 2) + '0');
            num /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
