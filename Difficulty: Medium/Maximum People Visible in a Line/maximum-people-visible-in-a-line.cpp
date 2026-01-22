
class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        vector<int> L(n, -1);
        vector<int> R(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                L[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                R[i] = st.top();
            }
            st.push(i);
        }

        int maxVis = 0;
        for (int i = 0; i < n; i++) {
            maxVis = max(maxVis, R[i] - L[i] - 1);
        }
        return maxVis;
    }
};