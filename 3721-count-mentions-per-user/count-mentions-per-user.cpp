class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        
        sort(events.begin(), events.end(), [&](const auto &a, const auto &b){
            int ta = stoi(a[1]), tb = stoi(b[1]);
            if (ta != tb) return ta < tb;
            return a[0] == "OFFLINE";
        });

        vector<int> res(numberOfUsers, 0);
        unordered_set<int> off;
        unordered_map<int, int> backOnline;

        for (auto &ev : events) {
            string type = ev[0];
            int t = stoi(ev[1]);

            vector<int> restore;
            for (int u : off) {
                if (backOnline[u] <= t) restore.push_back(u);
            }
            for (int u : restore) off.erase(u);

            if (type == "OFFLINE") {
                int u = stoi(ev[2]);
                backOnline[u] = t + 60;
                off.insert(u);
            } 
            else {
                string m = ev[2];

                if (m == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) res[i]++;
                } 
                else if (m == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++)
                        if (!off.count(i)) res[i]++;
                } 
                else {
                    stringstream ss(m);
                    string token;
                    while (ss >> token) {
                        int u = stoi(token.substr(2));
                        res[u]++;
                    }
                }
            }
        }

        return res;
    }
};
