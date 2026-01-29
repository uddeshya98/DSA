class Solution {
public:
    string firstNonRepeating(string &s) {
        vector<int> freq(26, 0);
        queue<char> q;
        string ans = "";

        for(char c : s) {
            freq[c - 'a']++;
            q.push(c);

            while(!q.empty() && freq[q.front() - 'a'] > 1)
                q.pop();

            if(q.empty()) ans += '#';
            else ans += q.front();
        }
        return ans;
    }
};
