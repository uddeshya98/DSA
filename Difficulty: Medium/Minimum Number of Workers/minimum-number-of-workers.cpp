class Solution {
  public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

      
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1) {
                int l = max(0, i - arr[i]);
                int r = min(n - 1, i + arr[i]);
                intervals.push_back({l, r});
            }
        }

  
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        int count = 0;
        int current = 0;
        int i = 0;

        while(current < n) {
            int farthest = -1;

            while(i < intervals.size() && intervals[i].first <= current) {
                farthest = max(farthest, intervals[i].second);
                i++;
            }

           
            if(farthest < current) return -1;

            count++;
            current = farthest + 1;
        }

        return count;
    }
};
