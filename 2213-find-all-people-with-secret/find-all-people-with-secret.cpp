class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        auto find = [&](auto self, int i) -> int {
            return parent[i] == i ? i : parent[i] = self(self, parent[i]);
        };

        auto unite = [&](int i, int j) {
            int rootI = find(find, i);
            int rootJ = find(find, j);
            if (rootI != rootJ) parent[rootI] = rootJ;
        };

        auto connected = [&](int i, int j) {
            return find(find, i) == find(find, j);
        };

        unite(0, firstPerson);

        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int i = 0, m = meetings.size();
        while (i < m) {
            int currentTime = meetings[i][2];
            vector<int> pool;
            while (i < m && meetings[i][2] == currentTime) {
                unite(meetings[i][0], meetings[i][1]);
                pool.push_back(meetings[i][0]);
                pool.push_back(meetings[i][1]);
                i++;
            }

            for (int p : pool) {
                if (!connected(p, 0)) {
                    parent[p] = p;
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (connected(i, 0)) {
                result.push_back(i);
            }
        }
        return result;
    }
};