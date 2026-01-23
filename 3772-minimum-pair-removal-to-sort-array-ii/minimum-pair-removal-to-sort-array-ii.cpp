class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

       
        vector<int> next_node(n);
        vector<int> prev_node(n);
        vector<long long> values(n);
        vector<bool> removed(n, false);

        for (int i = 0; i < n; ++i) {
            next_node[i] = i + 1;
            prev_node[i] = i - 1;
            values[i] = nums[i];
        }
        next_node[n - 1] = -1; 

       
        auto is_descent = [&](int i) {
            if (i < 0 || next_node[i] == -1) return false;
            return values[i] > values[next_node[i]];
        };

        
        int descent_count = 0;
        for (int i = 0; i < n; ++i) {
            if (is_descent(i)) descent_count++;
        }

        if (descent_count == 0) return 0;

        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        for (int i = 0; i < n - 1; ++i) {
            pq.push({values[i] + values[i + 1], i});
        }

        int ops = 0;

        while (descent_count > 0 && !pq.empty()) {
            auto [sum, u] = pq.top();
            pq.pop();

            
            if (removed[u]) continue;
            
            
            int v = next_node[u];
            if (v == -1) continue; 

            
            if (values[u] + values[v] != sum) continue;

            
            ops++;

            if (is_descent(prev_node[u])) descent_count--;
            if (is_descent(u)) descent_count--;
            if (is_descent(v)) descent_count--;

           
            values[u] += values[v];
            removed[v] = true;

           
            int next_v = next_node[v];
            next_node[u] = next_v;
            if (next_v != -1) {
                prev_node[next_v] = u;
            }
           
       
            if (is_descent(prev_node[u])) descent_count++;
            if (is_descent(u)) descent_count++;

           
            if (next_node[u] != -1) {
                pq.push({values[u] + values[next_node[u]], u});
            }
            
            if (prev_node[u] != -1) {
                pq.push({values[prev_node[u]] + values[u], prev_node[u]});
            }
        }

        return ops;
    }
};