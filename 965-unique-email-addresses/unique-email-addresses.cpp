class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(string s:emails){
            string t="",d="";
            int i=0;
            while(s[i]!='@'){
                if(s[i]=='+')
                    break;
                if(s[i]!='.')
                    t+=s[i];
                i++;
            }
            while(s[i]!='@')
                i++;
            d=s.substr(i);
            st.insert(t+d);
        }
        return st.size();
    }
};