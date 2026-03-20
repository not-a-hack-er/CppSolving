class Solution {
public:
    string reverseVowels(string s) {
        int st=0,l=s.size()-1;
        while(st<l)
        {
            if((s[st]=='a'||s[st]=='e'||s[st]=='i'||s[st]=='o'||s[st]=='u'||s[st]=='A'||s[st]=='E'||s[st]=='I'||s[st]=='O'||s[st]=='U') && (s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u'||s[l]=='A'||s[l]=='E'||s[l]=='I'||s[l]=='O'||s[l]=='U'))
            {
            swap(s[st],s[l]);
            st++;
            l--;
            }
            else if(s[st]!='a'&&s[st]!='e'&&s[st]!='i'&&s[st]!='o'&&s[st]!='u'&&s[st]!='A'&&s[st]!='E'&&s[st]!='I'&&s[st]!='O'&&s[st]!='U')
            {
            st++;
            }
           else
            l--;
        }
        return s;
        
    }
};