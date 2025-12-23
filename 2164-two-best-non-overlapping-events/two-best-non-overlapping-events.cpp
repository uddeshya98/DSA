class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int maxVal = 0;
        int ans = 0;
        
        for (auto& event : events) {
            while (!pq.empty() && pq.top().first < event[0]) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }
            ans = max(ans, maxVal + event[2]);
            pq.push({event[1], event[2]});
        }
        return ans;
    }
};