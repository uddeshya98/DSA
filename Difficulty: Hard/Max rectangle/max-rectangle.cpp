class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);
            while(!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maxArea(vector<vector<int>> &mat) {
        if(mat.empty()) return 0;
        int n = mat.size(), m = mat[0].size();
        vector<int> height(m, 0);
        int maxRect = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }
            maxRect = max(maxRect, largestRectangleArea(height));
        }
        return maxRect;
    }
};
