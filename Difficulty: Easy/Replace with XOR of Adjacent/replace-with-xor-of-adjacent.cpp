class Solution {
public:
    void replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;

        arr[0] = temp[0] ^ temp[1];

        for(int i = 1; i < n - 1; i++) {
            arr[i] = temp[i - 1] ^ temp[i + 1];
        }

        arr[n - 1] = temp[n - 2] ^ temp[n - 1];
    }
};