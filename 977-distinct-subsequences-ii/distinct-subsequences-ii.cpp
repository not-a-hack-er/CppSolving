class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1000000007;
        int t=0;
        vector<int> end(26,0);
        for(char ch:s){
            int ind=ch-'a';
            int oldt=t;
            int ns=(oldt+1-end[ind]+mod)%mod;
            t=(t+ns)%mod;
            end[ind]=(end[ind]+ns)%mod;
        }
        return t;
    }
};