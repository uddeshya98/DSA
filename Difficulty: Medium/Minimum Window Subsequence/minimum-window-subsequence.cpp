class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        

        if (n < m) return "";
        
        string minSub = "";
        int minLen = INT_MAX;
        
        int i = 0; 
        int j = 0; 
        
        while (i < n) {
      
            if (s1[i] == s2[j]) {
                j++;
            }
            
          
            if (j == m) {
                
                int end = i;
                int k = m - 1;
                
                while (k >= 0) {
                    if (s1[end] == s2[k]) {
                        k--;
                    }
                    end--;
                }
                
                
                int start = end + 1;
                int currentLen = i - start + 1;
                
                
                if (currentLen < minLen) {
                    minLen = currentLen;
                    minSub = s1.substr(start, currentLen);
                }
                
               
                j = 0;
                i = start + 1;
                continue; 
            }
            
            i++;
        }
        
        return minSub;
    }
};