class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        
        for(int i=0;i<s.size();i++){
        vector<int> freq(26,0);
            
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;
                int maxi=0;
                int mini=INT_MAX;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        maxi=max(maxi,freq[k]);
                        mini=min(mini,freq[k]);
                    }
                }
                ans+=maxi-mini;
            }
        }
        return ans;
    }
};