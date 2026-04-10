class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        
        left[0] = -1;
        int min_idx = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] <= arr[min_idx]){
                min_idx = i;
                left[i] = -1;
            } else {
                left[i] = min_idx;
            }
        }
        
        right[n-1] = -1;
        int max_idx = n-1;
        for(int i = n-2; i >= 0; i--){
            if(arr[i] >= arr[max_idx]){
                max_idx = i;
                right[i] = -1;
            } else {
                right[i] = max_idx;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(left[i] != -1 && right[i] != -1){
                return {arr[left[i]], arr[i], arr[right[i]]};
            }
        }
        
        return {};
    }
};