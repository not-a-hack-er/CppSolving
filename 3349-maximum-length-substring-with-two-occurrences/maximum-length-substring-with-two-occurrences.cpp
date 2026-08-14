class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26,0);
        int l=0,ans=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            while(freq[s[i]-'a']>2){
                freq[s[l]-'a']--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};