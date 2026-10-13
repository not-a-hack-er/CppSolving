class Solution {
  public:
    string reverse(string& S) {
        // code here
        stack<char> ans;
        for(int i=0;i<S.length();i++)
        {
            char ch=S[i];
            ans.push(ch);
        }
        for(int i=0;i<S.length();i++)
        {
            S[i]=ans.top();
            ans.pop();
        }
        return S;
    }
};