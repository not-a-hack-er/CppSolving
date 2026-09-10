class Solution {
public:
    int maxScore(string s) {
        int z=0;
        int o=0;
        for(char x:s){
            if(x=='1')
            o++;
        }
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0')
            z++;
            else
            o--;
            ans=max(ans,z+o);
        }
        return ans;
    }
};