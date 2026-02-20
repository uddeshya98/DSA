class Solution {
public:
    string findLargest(vector<int> &arr) {
        vector<string> strArr;
        for (int num : arr) {
            strArr.push_back(to_string(num));
        }
        
        sort(strArr.begin(), strArr.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        
        if (strArr[0] == "0") {
            return "0";
        }
        
        string result = "";
        for (const string &s : strArr) {
            result += s;
        }
        
        return result;
    }
};