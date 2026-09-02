class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++)
            dp[0][j]=grid[0][j];
        for(int i=1;i<n;i++){
            int mn1=INT_MAX,mn2=INT_MAX,pos=-1;
            for(int j=0;j<n;j++){
                if(dp[i-1][j]<mn1){
                    mn2=mn1;
                    mn1=dp[i-1][j];
                    pos=j;
                }
                else if(dp[i-1][j]<mn2)
                    mn2=dp[i-1][j];
            }
            for(int j=0;j<n;j++){
                if(j!=pos)
                    dp[i][j]=grid[i][j]+mn1;
                else
                    dp[i][j]=grid[i][j]+mn2;
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++)
            ans=min(ans,dp[n-1][j]);
        return ans;
    }
};