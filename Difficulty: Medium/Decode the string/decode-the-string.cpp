class Solution {
public:
    string decodedString(string &s) {
        stack<int> numSt;     
        stack<string> strSt;     
        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); 
            }
            else if (c == '[') {
                numSt.push(num);
                strSt.push(curr);
                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = numSt.top(); numSt.pop();
                string prev = strSt.top(); strSt.pop();

                string temp = "";
                for (int i = 0; i < repeat; i++) temp += curr;
                curr = prev + temp;
            }
            else {
                curr += c;  
            }
        }
        return curr;
    }
};
