class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max_time = 0;
        
       
        for (int pos : left) {
            max_time = max(max_time, pos);
        }
        
      
        for (int pos : right) {
            max_time = max(max_time, n - pos);
        }
        
        return max_time;
    }
};