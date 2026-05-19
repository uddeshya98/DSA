class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {
        vector<int> dist(1000, -1);
        queue<int> q;
        
        q.push(start);
        dist[start] = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (curr == end) return dist[curr];
            
            for (int x : arr) {
                int nxt = (curr * x) % 1000;
                
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[curr] + 1;
                    q.push(nxt);
                }
            }
        }
        
        return -1;
    }
};