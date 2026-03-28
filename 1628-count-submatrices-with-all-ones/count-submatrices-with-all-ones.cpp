class Solution {
public:
   int numSubmat(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();

    vector<int> height(m, 0);
    int ans = 0;

    for (int i = 0; i < n; i++) {

        
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1)
                height[j] += 1;
            else
                height[j] = 0;
        }

        
        stack<int> st;
        vector<int> sum(m, 0);

        for (int j = 0; j < m; j++) {

            while (!st.empty() && height[st.top()] >= height[j])
                st.pop();

            if (!st.empty()) {
                int prev = st.top();
                sum[j] = sum[prev] + height[j] * (j - prev);
            } else {
                sum[j] = height[j] * (j + 1);
            }

            st.push(j);
            ans += sum[j];
        }
    }

    return ans;
   }
};