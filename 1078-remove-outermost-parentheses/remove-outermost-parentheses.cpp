class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int k=0;
        string ans="";
        for(char ch:s){
            if(ch=='('){
                if(k>0)
                    ans+=ch;
                k++;
            }else{
                k--;
                if(k>0)
                    ans+=ch;
            }
        }
        return ans;
    }
};