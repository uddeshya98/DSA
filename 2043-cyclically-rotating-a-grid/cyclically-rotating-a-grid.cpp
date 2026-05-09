class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        for (int layer = 0; layer < min(m, n) / 2; layer++) {
            vector<int> elems;
            int top = layer, bottom = m - 1 - layer;
            int left = layer, right = n - 1 - layer;
            
            for (int col = left; col <= right; col++)
                elems.push_back(grid[top][col]);
            for (int row = top + 1; row <= bottom; row++)
                elems.push_back(grid[row][right]);
            for (int col = right - 1; col >= left; col--)
                elems.push_back(grid[bottom][col]);
            for (int row = bottom - 1; row >= top + 1; row--)
                elems.push_back(grid[row][left]);
            
            int sz = elems.size();
            int shift = k % sz;
            rotate(elems.begin(), elems.begin() + shift, elems.end());
            
            int idx = 0;
            for (int col = left; col <= right; col++)
                grid[top][col] = elems[idx++];
            for (int row = top + 1; row <= bottom; row++)
                grid[row][right] = elems[idx++];
            for (int col = right - 1; col >= left; col--)
                grid[bottom][col] = elems[idx++];
            for (int row = bottom - 1; row >= top + 1; row--)
                grid[row][left] = elems[idx++];
        }
        
        return grid;
    }
};