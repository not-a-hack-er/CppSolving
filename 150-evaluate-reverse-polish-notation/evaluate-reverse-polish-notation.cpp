class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, function<int(int,int)>> mp={
            {"+",[](int a,int b) {return a+b;}},
            {"-",[](int a,int b) {return a-b;}},
            {"*",[](int a,int b) {return a*b;}},
            {"/",[](int a,int b) {return a/b;}}
        };
        int result=0;
        for(string& t:tokens)
        {
            if(t=="+" || t=="-" || t=="/" || t=="*")
            {
                int b=st.top();
                st.pop();

                int a = st.top();
                st.pop();

                result = mp[t](a,b);
                st.push(result);
            }
            else{
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};