class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        int l = 1, r = *max_element(arr.begin(), arr.end()), ans = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long hrs = 0;
            for (int x : arr) 
                hrs += (x + mid - 1) / mid;
            if (hrs <= k) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
};
