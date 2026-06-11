class Solution {
public:
    string reverseWords(string s) {
        s=s+" ";
        string ans="",r="";
        int l = s.size();
        for(int i=0;i<l;i++)
        {
            if(s[i]==' ')
            {
                reverse(r.begin(),r.end());
                ans=ans+r;
                ans=ans+" ";
                r="";
            }
            else
            {
                r=r+s[i];
            }
        }
        ans.pop_back();
        return ans;
    }
};