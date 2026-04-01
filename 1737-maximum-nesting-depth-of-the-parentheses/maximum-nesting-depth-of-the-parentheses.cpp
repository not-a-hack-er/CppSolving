class Solution {
public:
    int maxDepth(string s) {
        int co=0;int maxi=0;
        stack<char> st;
        for(char c:s)
        {
            if(c=='(')
            {
            st.push(c);
            co++;
            maxi=max(maxi,co);
            }
            else if(c==')')
            {
            st.pop();
            co--;
            }
            else 
            continue;
        }
        return maxi;
    }
};