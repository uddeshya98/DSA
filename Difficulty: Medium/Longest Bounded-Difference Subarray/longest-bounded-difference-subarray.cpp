class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        deque<int> maxD, minD;
        int l = 0, bestL = 0, bestLen = 0;

        for (int r = 0; r < n; r++) {
            while (!maxD.empty() && arr[maxD.back()] <= arr[r]) 
                maxD.pop_back();
            maxD.push_back(r);

            while (!minD.empty() && arr[minD.back()] >= arr[r]) 
                minD.pop_back();
            minD.push_back(r);

            while (!maxD.empty() && !minD.empty() && 
                   arr[maxD.front()] - arr[minD.front()] > x) {
                if (maxD.front() == l) maxD.pop_front();
                if (minD.front() == l) minD.pop_front();
                l++;
            }

            if (r - l + 1 > bestLen) {
                bestLen = r - l + 1;
                bestL = l;
            }
        }

        return vector<int>(arr.begin() + bestL, arr.begin() + bestL + bestLen);
    }
};