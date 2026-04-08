class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            while (l < r && arr[l] == 0)
            l++;
            while (l < r && arr[r] == 1)
            r--;
            if (l < r) swap(arr[l], arr[r]);
        }
    }
};