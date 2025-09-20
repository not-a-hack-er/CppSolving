class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        st.push(-1); // sentinel to help calculate length
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // reset base for counting
                } else {
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }
        return maxLength;
    }

};