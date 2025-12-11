class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,int> rowMin, rowMax, colMin, colMax;

        // First pass: compute min/max y per row, and min/max x per column
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            // For each row x, track min and max column y
            if (!rowMin.count(x)) rowMin[x] = y;
            else rowMin[x] = min(rowMin[x], y);

            if (!rowMax.count(x)) rowMax[x] = y;
            else rowMax[x] = max(rowMax[x], y);

            // For each column y, track min and max row x
            if (!colMin.count(y)) colMin[y] = x;
            else colMin[y] = min(colMin[y], x);

            if (!colMax.count(y)) colMax[y] = x;
            else colMax[y] = max(colMax[y], x);
        }

        int ans = 0;

        // Second pass: count buildings that are strictly inside both their row and column
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            // left & right exist if y is strictly between minY[x] and maxY[x]
            // above & below exist if x is strictly between minX[y] and maxX[y]
            if (rowMin[x] < y && y < rowMax[x] &&
                colMin[y] < x && x < colMax[y]) {
                ans++;
            }
        }

        return ans;
    }
};
