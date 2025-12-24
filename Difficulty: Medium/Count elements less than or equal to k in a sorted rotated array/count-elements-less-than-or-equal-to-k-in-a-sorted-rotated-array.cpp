class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        int pivot = low;
        int count1 = upper_bound(arr.begin(), arr.begin() + pivot, x) - arr.begin();
        int count2 = upper_bound(arr.begin() + pivot, arr.end(), x) - (arr.begin() + pivot);
        
        return count1 + count2;
    }
};