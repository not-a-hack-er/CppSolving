class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string cur="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(cur);
                cur="";
            }else if(s[i]==')'){
                reverse(cur.begin(),cur.end());
                cur=st.top()+cur;
                st.pop();
            }else{
                cur+=s[i];
            }
        }
        return cur;   
    }
};