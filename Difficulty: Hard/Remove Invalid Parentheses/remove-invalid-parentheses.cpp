class Solution {
public:
    vector<string> validParenthesis(string &s) {
        unordered_set<string> visited;
        queue<string> q;
        vector<string> result;
        bool found = false;
        
        q.push(s);
        visited.insert(s);
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            if (isValid(curr)) {
                result.push_back(curr);
                found = true;
            }
            
            if (found) continue;
            
            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] != '(' && curr[i] != ')') continue;
                string next = curr.substr(0, i) + curr.substr(i + 1);
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
    
private:
    bool isValid(const string &s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }
};