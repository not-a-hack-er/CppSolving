class Solution {
public:
int solve(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(i<0 || j<0)
        return INT_MAX;
    if(i==0 && j==0)
        return grid[0][0];
    if(dp[i][j]!=-1)
        return dp[i][j];
    int up=INT_MAX,left=INT_MAX;
    if(i>0)
         up=grid[i][j]+solve(i-1,j,grid,dp);
    if(j>0)
        left=grid[i][j]+solve(i,j-1,grid,dp);

    return dp[i][j]=min(up,left);
    
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);

    }
};