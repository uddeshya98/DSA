class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
     
        sort(arr.begin(), arr.end());
        
        vector<int> results;
        
        
        for (const auto& query : queries) {
            int lower = query[0];
            int upper = query[1];
            
            auto it1 = lower_bound(arr.begin(), arr.end(), lower);
            
       
            auto it2 = upper_bound(arr.begin(), arr.end(), upper);
            
          
            results.push_back(it2 - it1);
        }
        
        return results;
    }
};