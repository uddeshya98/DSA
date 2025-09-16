class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<long long> st;
        for (string &s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = 0;
                if (s == "+") res = a + b;
                else if (s == "-") res = a - b;
                else if (s == "*") res = a * b;
                else if (s == "/") {
                    res = a / b;
                    if ((a ^ b) < 0 && a % b != 0) res--;
                }
                else if (s == "^") res = pow(a, b);
                st.push(res);
            } else {
                st.push(stoi(s));
            }
        }
        return (int)st.top();
    }
};
