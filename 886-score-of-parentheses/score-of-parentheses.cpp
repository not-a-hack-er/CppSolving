class Solution {
public:
    int scoreOfParentheses(string s) {
int c=0;
stack<int> st;
for(char c:s)
{
    int val=0;
    if(c=='(')
    st.push(0);
    else
    {
        while(st.top()!=0)
        {
        val+=st.top();
        st.pop();
        }

        val=max(2*val,1);
        st.pop();
        st.push(val);
    }
}
while(!st.empty()) 
{
c+=st.top();
st.pop();
}
return c;
    }
};