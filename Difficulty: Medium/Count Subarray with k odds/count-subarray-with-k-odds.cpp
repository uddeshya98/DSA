class Solution {
  public:
    
    int countAtMost(vector<int>& arr, int k) {
        if (k < 0) return 0;
        
        int count = 0;
        int left = 0;
        int oddCount = 0;
        int n = arr.size();
        
        for (int right = 0; right < n; right++) {
           
            if (arr[right] % 2 != 0) {
                oddCount++;
            }
            
         
            while (oddCount > k) {
                if (arr[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }
            
          
            count += (right - left + 1);
        }
        return count;
    }

    int countSubarrays(vector<int>& arr, int k) {
        return countAtMost(arr, k) - countAtMost(arr, k - 1);
    }
};