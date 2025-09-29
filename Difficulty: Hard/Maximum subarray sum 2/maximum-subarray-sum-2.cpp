class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++) prefix[i+1] = prefix[i] + arr[i];
        
        deque<int> dq;
        long long ans = LLONG_MIN;
        
        for(int i=a;i<=n;i++){
            while(!dq.empty() && dq.front() < i-b) dq.pop_front();
            while(!dq.empty() && prefix[dq.back()] >= prefix[i-a]) dq.pop_back();
            dq.push_back(i-a);
            ans = max(ans, prefix[i] - prefix[dq.front()]);
        }
        return (int)ans;
    }
};






