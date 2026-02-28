class Solution {
public:
    vector<int> findClosestPair(vector<int>& arr1, vector<int>& arr2, int x) {
        int i = 0, j = arr2.size() - 1;
        int diff = INT_MAX;
        vector<int> ans(2);

        while (i < arr1.size() && j >= 0) {
            int sum = arr1[i] + arr2[j];
            int d = abs(sum - x);

            if (d < diff) {
                diff = d;
                ans[0] = arr1[i];
                ans[1] = arr2[j];
            }

            if (sum > x) j--;
            else i++;
        }
        return ans;
    }
};