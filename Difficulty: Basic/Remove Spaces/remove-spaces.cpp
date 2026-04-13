class Solution {
  public:
    string removeSpaces(string& s) {
        string res ="";
        
        for( char ch : s){
            if(ch != ' '){
                res += ch;
                
            }
        }
        return res;
        
    }
};