class Solution {
public:
    int n;
    unordered_set<string> st;
    int maxLen;
    void solve(string& s,int i,string &curr, int count){
        if(count<0)
        return;
        if(i==n){
            if(count==0){
                if(curr.length()>maxLen){
                    maxLen=curr.length();
                    st.clear();
                }
                if(curr.length()==maxLen)
                st.insert(curr);
            }
            return;
        }
        if(s[i]!=')' && s[i]!='('){
            curr.push_back(s[i]);
            solve(s,i+1,curr,count);
            curr.pop_back();
            return;
        }
        curr.push_back(s[i]);
        solve(s,i+1,curr,count+(s[i]=='('? 1:-1));
        curr.pop_back();
        solve(s,i+1,curr,count);
    }
    vector<string> removeInvalidParentheses(string s) {
        n=s.length();
        st.clear();
        maxLen=0;
        string curr="";
        solve(s,0,curr,0);
        return vector<string>(st.begin(),st.end());
    }
};