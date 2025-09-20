class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        vector<int> prev(n), next(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int s = next[i] - prev[i] - 1;
            if (s >= arr[i]) ans = max(ans, s);
        }
        return ans;
    }
};
