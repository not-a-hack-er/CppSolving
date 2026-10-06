class Solution {
public:
    string removeSub(string& s,string &matchStr){
        stack<char> st;
        for(char &ch:s){
            if(ch==matchStr[1] && !st.empty() && st.top()==matchStr[0] ){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        int score=0;
        string maxstr=(x>=y)?"ab":"ba";
        string minstr=(x>=y)?"ba":"ab";
        string tempfirst=removeSub(s,maxstr);
        int l=tempfirst.length();

        int charremoved=(n-l);
        score+=(charremoved/2)*max(x,y);

        string tempsecond=removeSub(tempfirst,minstr);
        charremoved=tempfirst.length() - tempsecond.length();
        score+=(charremoved/2)*min(x,y);
        return score;
    }
};