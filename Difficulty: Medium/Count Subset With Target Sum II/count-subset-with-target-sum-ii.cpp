class Solution {
public:
    void getSums(vector<int>& arr, vector<long long>& sums) {
        int n = arr.size();
        int total = 1 << n;
        
        for (int mask = 0; mask < total; mask++) {
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    sum += arr[i];
            }
            sums.push_back(sum);
        }
    }

    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();
        
        vector<int> leftArr(arr.begin(), arr.begin() + n/2);
        vector<int> rightArr(arr.begin() + n/2, arr.end());
        
        vector<long long> leftSums, rightSums;

        getSums(leftArr, leftSums);
        getSums(rightArr, rightSums);
        
        sort(rightSums.begin(), rightSums.end());
        
        long long count = 0;
        
        for (long long ls : leftSums) {
            long long need = k - ls;
            auto l = lower_bound(rightSums.begin(), rightSums.end(), need);
            auto r = upper_bound(rightSums.begin(), rightSums.end(), need);
            count += (r - l);
        }
        
        return count;
    }
};
