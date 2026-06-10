class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns=s.size();
        int nt=t.size();
        int k=0;
        bool check = false;
        for(int i=0;i<nt;i++)
        {
            
            if(t[i]==s[k])
            {
                check=true;
                k++;
            }
        }
        return k==ns;
    }
};