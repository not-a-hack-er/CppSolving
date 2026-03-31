class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        int sign = 1;
        int ans = 0;
        long long currNo = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                currNo = s[i] - '0';

                while (i + 1 < n && isdigit(s[i + 1])) {
                    currNo = currNo * 10 + (s[i + 1] - '0');
                    i++;
                }

                currNo = currNo * sign;
                ans += currNo;
                currNo = 0;
            }
            else if (s[i] == '+') {
                sign = 1;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            else if (s[i] == '(') {
                st.push(ans);   
                st.push(sign);  
                ans = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                int prevSign = st.top(); st.pop();
                ans = prevSign * ans;

                int prevAns = st.top(); st.pop();
                ans = ans + prevAns;
            }
        }

        return ans;
    }
};