class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
       
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        vector<vector<int>> ans;
        
       
        for(int i = 0; i < arr.size() - 1; i++) {
            int currentDiff = arr[i+1] - arr[i];
            
            
            if(currentDiff < minDiff) {
                minDiff = currentDiff;
                ans.clear(); 
                ans.push_back({arr[i], arr[i+1]});
            }
           
            else if(currentDiff == minDiff) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        
        return ans;
    }
};