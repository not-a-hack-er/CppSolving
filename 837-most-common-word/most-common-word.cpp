class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int> mp;
        set<string> st; string curr="";
        paragraph+=" ";
        for(auto b:banned)
        {
            st.insert(b);
        }
        for(int i=0;i<paragraph.size();i++)
        {
        if(paragraph[i]>='a' && paragraph[i]<='z')
        {
            curr+=paragraph[i];
        }
        else if(paragraph[i]>='A' && paragraph[i]<='Z')
        {
            curr+=tolower(paragraph[i]);
        }
        else
        {
            if(curr!="")
            {
                mp[curr]++;
            }
            curr="";
        }
        }
        int maxi=-1;
        string ans="";
        for(auto i:mp)
        {
            if(st.count(i.first)==0)
            {
                if(i.second>maxi)
                {
                    maxi=i.second;
                    ans=i.first;
                }
            }
        }
        return ans;
    }
};