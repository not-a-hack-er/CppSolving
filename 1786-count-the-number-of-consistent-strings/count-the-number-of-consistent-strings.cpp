class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> freq(26,0);
        for(char ch:allowed)
            freq[ch-'a']=1;
        int ans=0;
        for(string w:words){
            bool flag=true;
            for(char ch:w){
                if(freq[ch-'a']==0){
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans++;
        }
        return ans;
    }
};