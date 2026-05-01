class Solution {
public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;
        
        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
            
            if (pq.size() > k) {
                pq.pop();
            }
            
            if (pq.size() < k) {
                ans.push_back(-1);
            } else {
                ans.push_back(pq.top());
            }
        }
        
        return ans;
    }
};