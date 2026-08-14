class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,0);
        for(char ch:s)
            freq[ch-'a']++;
        string ans="";
        for(char ch:order){
            while(freq[ch-'a']>0){
                ans+=ch;
                freq[ch-'a']--;
            }
        }
        for(char c='a';c<='z';c++){
            while(freq[c-'a']>0){
                ans+=c;
                freq[c-'a']--;
            }
        }
        return ans;
    }
};