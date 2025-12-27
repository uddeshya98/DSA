class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }
        
        vector<int> count(n, 0);
        
        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }
            
            if (available.empty()) {
                auto [finishTime, room] = busy.top();
                busy.pop();
                busy.push({finishTime + (end - start), room});
                count[room]++;
            } else {
                int room = available.top();
                available.pop();
                busy.push({end, room});
                count[room]++;
            }
        }
        
        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[maxRoom]) {
                maxRoom = i;
            }
        }
        
        return maxRoom;
    }
};