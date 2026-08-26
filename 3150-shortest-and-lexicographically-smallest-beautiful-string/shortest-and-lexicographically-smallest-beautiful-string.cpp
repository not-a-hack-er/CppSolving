class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        for(int i=0;i<s.size();i++){
            // if(s[i]!='1')
            // continue;
            int c=0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='1')
                    c++;
                if(c==k)
                {
                    string temp=s.substr(i,j-i+1);
                    if(ans==""||temp.size()<ans.size()|| (temp.size()==ans.size() && temp<ans))
                    ans=temp;
                     break;
                }
                //break;
            }
        }  return ans;
    }
  
};