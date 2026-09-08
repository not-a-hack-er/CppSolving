class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                words.push_back(temp);
                temp="";
            }else{
                temp+=s[i];
            }
        }
        words.push_back(temp);
        if(pattern.size()!=words.size())
            return false;

        string mp[26];
        set<string> u;
        for(int i=0;i<pattern.size();i++){
            int x=pattern[i]-'a';
            if(mp[x]==""){
                if(u.count(words[i]))
                    return false;
                mp[x]=words[i];
                u.insert(words[i]);    
            }else{
                if(mp[x]!=words[i])
                    return false;
            }
        }
        return true;
    }
};