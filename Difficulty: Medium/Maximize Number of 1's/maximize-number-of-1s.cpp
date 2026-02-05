class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int i = 0, j = 0, zero = 0, ans = 0;

        while (j < arr.size()) {
            if (arr[j] == 0) zero++;

            while (zero > k) {
                if (arr[i] == 0) zero--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

