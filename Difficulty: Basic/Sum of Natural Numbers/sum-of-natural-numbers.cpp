class Solution {
  public:
    int findSum(int n) {
        // code here
        if(n==0){
        return 0;
        }
        int res = n*(n+1);
      
        return res/2;
        
    }
};
