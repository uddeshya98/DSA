class Solution {
public:
    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        int total = 0;
        vector<int> st;
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.back()] >= arr[i]) {
                st.pop_back();
            }
            
            int next_smaller_idx = st.empty() ? n : st.back();
            total += (next_smaller_idx - i);
            
            st.push_back(i);
        }
        
        return total;
    }
};