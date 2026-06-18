class Solution {
public:
int operate(int a, int b,string t)
{
    if(t=="+")
    return a+b;
    if(t=="-")
    return a-b;
    if(t=="*")
    return (long)a*(long)b;
    if(t=="/")
    return a/b;
    return -1;
    
}
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result=0;
        for(string& t:tokens)
        {
            if(t=="+" || t=="-" || t=="/" || t=="*")
            {
                int b=st.top();
                st.pop();

                int a = st.top();
                st.pop();

                result = operate(a,b,t);
                st.push(result);
            }
            else{
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};