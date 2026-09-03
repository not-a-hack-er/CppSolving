class Solution {
public:
int ans=0;
    int maxUniqueSplit(string s) {
        set<string> st;
        rec(0,s,st);
        return ans;
    }
    void rec(int i,string& s,set<string> &st){
        if(i==s.size()){
            ans=max(ans,(int)st.size());
            return;
        }
        for(int j=i;j<s.size();j++){
            string temp=s.substr(i,j-i+1);
            if(st.find(temp)==st.end()){
                st.insert(temp);
                rec(j+1,s,st);
                st.erase(temp);
            }
        }

    }
};