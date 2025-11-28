class Solution {
  public:
    vector<int> subsetXOR(int n) {
     
        int total_xor;
        int rem = n % 4;
        
        if (rem == 0) total_xor = n;
        else if (rem == 1) total_xor = 1;
        else if (rem == 2) total_xor = n + 1;
        else total_xor = 0;
        
      
        int remove_val = total_xor ^ n;
        
       
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            if (i == remove_val) continue;
            result.push_back(i);
        }
        
        return result;
    }
};