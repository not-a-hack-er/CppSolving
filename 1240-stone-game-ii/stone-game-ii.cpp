class Solution {
public:
int dp[105][105];
int suffix[105];
int n;
int solve(int i,int m,vector<int>& piles){
    if(i>=n)
        return 0;
    if(dp[i][m]!=-1)
        return dp[i][m];
    int ans=0;
    for(int x=1;x<=2*m && i+x<=n;x++){
        int t=suffix[i]-suffix[i+x];
        int op=solve(i+x,max(m,x),piles);
        ans=max(ans,t+suffix[i+x]-op);
    }
    return dp[i][m]=ans;

}
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        suffix[n]=0;
        for(int i=n-1;i>=0;i--)
            suffix[i]=suffix[i+1]+piles[i];
        return solve(0,1,piles);
    }
};