class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';
            int val=26-x;
            ans+=val*(i+1);
        }
        return ans;
    }
};