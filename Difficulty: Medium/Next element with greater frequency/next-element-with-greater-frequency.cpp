class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        
       
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        
        
        stack<int> st;  
        
      
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            
            
            while (!st.empty() && freq[st.top()] <= freq[curr]) {
                st.pop();
            }
            
           
            if (!st.empty()) {
                ans[i] = st.top();
            }
            
           
            st.push(curr);
        }
        
        return ans;
    }
};
