class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<int> st;
        string ans="";
        unordered_set<int> mp;
        for(int i=0;i<n;i++){
            if(s[i] == '(')
                st.push(i);
            else if(s[i]==')'){
                if(!st.empty() && s[st.top()]=='(')
                    st.pop();
                else
                    mp.insert(i);
            }
            
        }
        while(!st.empty()){
            mp.insert(st.top());
            st.pop();
        }
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end())
            ans+=s[i];
        }
        return ans;
    }
};