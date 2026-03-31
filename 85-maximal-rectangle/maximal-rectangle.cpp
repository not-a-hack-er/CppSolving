class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.empty()) return 0;

        int n = mat.size(), m = mat[0].size();
        vector<int> heights(m, 0);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            maxi = max(maxi, largestRectangleArea(heights));
        }

        return maxi;
    }
};