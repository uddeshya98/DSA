class Solution {
public:
    long long merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> left(n1), right(n2);
        for(int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for(int j = 0; j < n2; j++)
            right[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        long long inv = 0;

        while(i < n1 && j < n2) {
            if(left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                inv += (n1 - i);
            }
        }

        while(i < n1)
            arr[k++] = left[i++];

        while(j < n2)
            arr[k++] = right[j++];

        return inv;
    }

    long long mergeSort(vector<int>& arr, int l, int r) {
        long long inv = 0;
        if(l < r) {
            int m = l + (r - l) / 2;
            inv += mergeSort(arr, l, m);
            inv += mergeSort(arr, m + 1, r);
            inv += merge(arr, l, m, r);
        }
        return inv;
    }

    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
