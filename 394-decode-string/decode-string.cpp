class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (char c : s) {
            if (c != ']') {
                st.push(string(1, c));
            } 
            else {
                
                string curr = "";
                while (st.top() != "[")
                {
                    curr = st.top() + curr;
                    st.pop();
                }
                st.pop(); 

           
                string num = "";
                while (!st.empty() && isdigit(st.top()[0]))
                {
                    num = st.top() + num;
                    st.pop();
                }

                int k = stoi(num);

                string temp = "";
                while (k--) temp += curr;

                st.push(temp);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};