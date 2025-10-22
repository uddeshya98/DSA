class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        for (; i < n && i <= k; ++i) pq.push(arr[i]);
        int idx = 0;
        for (; i < n; ++i) {
            arr[idx++] = pq.top(); pq.pop();
            pq.push(arr[i]);
        }
        while (!pq.empty()) {
            arr[idx++] = pq.top(); pq.pop();
        }
    }
};






