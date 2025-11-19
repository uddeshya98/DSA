class Solution {
public:
    int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

       
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

      
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>> 
        > pq;

        pq.push({0, {0,0}});

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int effort = it.first;
            int x = it.second.first;
            int y = it.second.second;

          
            if (x == n-1 && y == m-1) return effort;

            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int cost = abs(mat[x][y] - mat[nx][ny]);
                    int newEffort = max(effort, cost);

                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
