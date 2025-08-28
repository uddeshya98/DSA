class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, zeros = 0, ans = 0;

        for (int right = 0; right < n; right++) {
            if (arr[right] == 0) zeros++;

          
            while (zeros > k) {
                if (arr[left] == 0) zeros--;
                left++;
            }

           
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
