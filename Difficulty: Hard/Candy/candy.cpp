class Solution {
public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> candy(n, 1);

       
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

      
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        int total = 0;
        for (int c : candy) total += c;

        return total;
    }
};
