class Solution {
  public:
    int largest(vector<int> &arr ) {
        int n = arr.size();
        int largest =arr[0];
        for(int i = 0; i<n; i++){
            if( largest < arr[i])
            largest = arr[i];
              
        }
            return largest;
        
    }
    
};
