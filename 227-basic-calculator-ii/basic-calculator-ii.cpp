

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long currentNumber = 0;
        char lastOperator = '+';
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            
            if (isdigit(c))
             {
                currentNumber = currentNumber * 10 + (c - '0');
            }

            
            if ((!isdigit(c) && !isspace(c)) || i == n - 1)
             {
                if (lastOperator == '+') {
                    st.push(currentNumber);
                } else if (lastOperator == '-') {
                    st.push(-currentNumber);
                } else if (lastOperator == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * currentNumber); 
                } else if (lastOperator == '/')
                 {
                    int top = st.top();
                    st.pop();
                    st.push(top / currentNumber); 
                }
                
               
                lastOperator = c;
                currentNumber = 0;
            }
        }

        
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};