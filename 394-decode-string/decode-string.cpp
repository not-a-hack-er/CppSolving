class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> numSt;

        string curString = "";
        int curNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                curNum = curNum * 10 + (c - '0');
            }
            else if (c == '[') {
                st.push(curString);
                numSt.push(curNum);

                curString = "";
                curNum = 0;
            }
            else if (c == ']') {
                int num = numSt.top(); numSt.pop();
                string prevString = st.top(); st.pop();

                string temp = "";
                for (int i = 0; i < num; i++) {
                    temp += curString;
                }

                curString = prevString + temp;
            }
            else {
                curString += c;
            }
        }

        return curString;
    }
};