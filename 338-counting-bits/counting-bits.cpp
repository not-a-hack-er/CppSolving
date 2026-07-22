class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        if(n==0)
            return result;
        result[0]=0;
        for(int i=1;i<=n;i++){
            result[i]=__builtin_popcount(i);
        }
        return result;
    }
};