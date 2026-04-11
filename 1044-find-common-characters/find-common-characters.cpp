class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> finalFreq(26,100);
        for(int i=0;i<words.size();i++)
        {
            vector<int> currFreq(26,0);
            for(auto c:words[i])
            currFreq[c-'a']++;
            for(char c='a';c<='z';c++)
            finalFreq[c-'a'] = min(finalFreq[c-'a'],currFreq[c-'a']);
        }
        vector<string> ans;
        for(char c='a';c<='z';c++)
        {
            while(finalFreq[c-'a']--)
            ans.push_back(string(1,c));
        }
        return ans;
    }
};