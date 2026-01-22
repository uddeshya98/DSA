class Solution {
public:
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long sumMax = 0, sumMin = 0;
        vector<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.back()] < arr[i])) {
                int mid = st.back();
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                int right = i;
                sumMax += 1LL * arr[mid] * (mid - left) * (right - mid);
            }
            st.push_back(i);
        }

        st.clear();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.back()] > arr[i])) {
                int mid = st.back();
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                int right = i;
                sumMin += 1LL * arr[mid] * (mid - left) * (right - mid);
            }
            st.push_back(i);
        }

        return (int)(sumMax - sumMin);
    }
};

