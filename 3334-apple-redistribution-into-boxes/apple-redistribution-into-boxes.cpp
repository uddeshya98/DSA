class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for (int x : apple) total += x;
        sort(capacity.rbegin(), capacity.rend());
        int used = 0, sum = 0;
        for (int x : capacity) {
            sum += x;
            used++;
            if (sum >= total) break;
        }
        return used;
    }
};
