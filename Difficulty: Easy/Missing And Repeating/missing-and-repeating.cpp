class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        
        long long S = n * (n + 1) / 2;                 
        long long S2 = n * (n + 1) * (2*n + 1) / 6;    
        
        long long sumArr = 0, sumSqArr = 0;
        
        for(long long x : arr){
            sumArr += x;
            sumSqArr += x * x;
        }
        
        long long X = sumArr - S;           
        long long Y = (sumSqArr - S2) / X;      
        
        long long repeating = (X + Y) / 2;
        long long missing   = (Y - X) / 2;
        
        return {(int)repeating, (int)missing};
    }
};
