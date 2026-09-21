class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k,0);
        vector<long long> dp(k,0);
        for(int x:nums){
            vector<long long> temp(k,0);
            temp[x%k]++;
            for(int r=0;r<k;r++){
                if(dp[r]>0){
                    int nr=(r*(x%k))%k;
                    temp[nr]+=dp[r];
                }
            }
            dp=temp;
            for(int r=0;r<k;r++){
                res[r]+=dp[r];
            }
        }
        vector<long long> ans(k);
        for(int i=0;i<k;i++)
            ans[i]=res[i];
        return ans;
    }
};