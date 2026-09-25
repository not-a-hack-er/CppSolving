class Solution {
public:
    set<string> solve(string& s,int& i){
        set<string> ans;
        set<string> cur;
        while(i<s.size() && s[i]!='}'){
            if(s[i]==','){
                for(string x:cur)
                    ans.insert(x);
                cur.clear();
                i++;
            }else{
                set<string> temp;
                if(s[i]=='{'){
                    i++;
                    temp=solve(s,i);
                    i++;
                }else{
                    temp.insert(string(1,s[i]));
                    i++;
                }
                if(cur.empty()){
                    cur=temp;
                }else{
                    set<string> next;
                    for(string a:cur){
                        for(string b:temp){
                            next.insert(a+b);
                        }
                    } 
                    cur=next;
                }
            }
        }
        for(string x:cur)
        ans.insert(x);
        return ans;
    }
    vector<string> braceExpansionII(string expression) {
        int i=0;
        set<string> st=solve(expression,i);
        vector<string> ans(st.begin(),st.end());
        return ans;
    }
};