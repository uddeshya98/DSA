class Solution {
public:
    bool palindromePair(vector<string>& arr) {
        unordered_map<string, int> mp;
        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]] = i;

        auto isPalin = [](const string& s, int l, int r) {
            while (l < r)
                if (s[l++] != s[r--]) return false;
            return true;
        };

        for (int i = 0; i < arr.size(); i++) {
            string& s = arr[i];
            int n = s.size();
            for (int k = 0; k <= n; k++) {
                string left = s.substr(0, k);
                string right = s.substr(k);
                string revL(left.rbegin(), left.rend());
                string revR(right.rbegin(), right.rend());

                if (isPalin(left, 0, (int)left.size() - 1) && mp.count(revR) && mp[revR] != i)
                    return true;
                if (isPalin(right, 0, (int)right.size() - 1) && mp.count(revL) && mp[revL] != i)
                    return true;
            }
        }
        return false;
    }
};