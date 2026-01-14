class Solution {
    struct Event {
        int y;
        int type;
        int x1, x2;
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };
    
    vector<int> count;
    vector<long long> len;
    vector<int> X;

    void update(int node, int start, int end, int q_start, int q_end, int val) {
        if (q_start > end || q_end < start) return;
        if (q_start <= start && end <= q_end) {
            count[node] += val;
        } else {
            int mid = start + (end - start) / 2;
            update(2 * node, start, mid, q_start, q_end, val);
            update(2 * node + 1, mid + 1, end, q_start, q_end, val);
        }
        if (count[node] > 0) {
            len[node] = (long long)X[end + 1] - X[start];
        } else {
            if (start != end) {
                len[node] = len[2 * node] + len[2 * node + 1];
            } else {
                len[node] = 0;
            }
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<int> coords;
        
        for (auto& sq : squares) {
            int x = sq[0];
            int y = sq[1];
            int l = sq[2];
            events.push_back({y, 1, x, x + l});
            events.push_back({y + l, -1, x, x + l});
            coords.push_back(x);
            coords.push_back(x + l);
        }
        
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());
        X = coords;
        
        sort(events.begin(), events.end());
        
        int m = X.size();
        if (m <= 1) return 0.0;
        
        count.assign(4 * m, 0);
        len.assign(4 * m, 0);
        
        struct Strip {
            int y1, y2;
            long long width;
        };
        vector<Strip> strips;
        
        long long totalArea = 0;
        
        for (int i = 0; i < events.size(); ++i) {
            int j = i;
            while (j < events.size() && events[j].y == events[i].y) {
                int idx1 = lower_bound(X.begin(), X.end(), events[j].x1) - X.begin();
                int idx2 = lower_bound(X.begin(), X.end(), events[j].x2) - X.begin();
                if (idx1 < idx2) {
                    update(1, 0, m - 2, idx1, idx2 - 1, events[j].type);
                }
                j++;
            }
            
            if (j < events.size()) {
                int current_y = events[i].y;
                int next_y = events[j].y;
                if (next_y > current_y) {
                    long long active_width = len[1];
                    long long strip_area = active_width * (long long)(next_y - current_y);
                    totalArea += strip_area;
                    strips.push_back({current_y, next_y, active_width});
                }
            }
            i = j - 1;
        }
        
        double target = (double)totalArea / 2.0;
        double currentTotal = 0;
        
        for (const auto& s : strips) {
            double stripArea = (double)s.width * (s.y2 - s.y1);
            if (currentTotal + stripArea >= target) {
                if (s.width == 0) return s.y1;
                double needed = target - currentTotal;
                return s.y1 + (needed / s.width);
            }
            currentTotal += stripArea;
        }
        
        return events.back().y;
    }
};
