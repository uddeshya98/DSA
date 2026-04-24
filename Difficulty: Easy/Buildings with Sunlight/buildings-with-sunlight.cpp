class Solution {
public:
    int visibleBuildings(vector<int>& arr) {
        int count = 0;
        int maxHeight = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= maxHeight) {
                count++;
                maxHeight = arr[i];
            }
        }
        
        return count;
    }
};