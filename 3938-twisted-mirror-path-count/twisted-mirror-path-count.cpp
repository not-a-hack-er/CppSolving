class Solution {
public:
    int m,n;
    int MOD=1e9+7;
    int left=0;
    int up=1;

    int solve(vector<vector<int>>& grid,int i,int j,int cameFrom,vector<vector<array<int,2>>>& dp){
        if(i>=m || j>=n)
        return 0;

        if(i==m-1 && j==n-1)
            return 1;

        if(dp[i][j][cameFrom]!=-1)
            return dp[i][j][cameFrom];

        if(grid[i][j]==1){
            if(cameFrom==left){
                return dp[i][j][cameFrom]=solve(grid,i+1,j,up,dp);
            }else{
                return dp[i][j][cameFrom]=solve(grid,i,j+1,left,dp);
            }
        }

        int total=0;
        total=(total+solve(grid,i,j+1,left,dp))%MOD;
        total=(total+solve(grid,i+1,j,up,dp))%MOD;

        return dp[i][j][cameFrom]=total;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
         vector<vector<array<int,2>>> dp(
            m, vector<array<int,2>>(n, {-1,-1})
        );
        return solve(grid,0,0,left,dp);
    }
};