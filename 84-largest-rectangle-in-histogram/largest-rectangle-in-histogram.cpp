class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int mx = INT_MIN;

        for(int i = 0; i <= heights.size(); i++)
        {
            while(!st.empty() &&
                  (i == heights.size() || heights[st.top()] > heights[i]))
            {
                int current = st.top();
                st.pop();

                int width;

                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                mx = max(mx, width * heights[current]);
            }

            st.push(i);
        }

        return mx;
    }
};