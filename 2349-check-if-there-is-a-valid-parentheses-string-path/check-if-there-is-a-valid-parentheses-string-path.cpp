class Solution {
public:
int m,n;
int dp[100][100][201];
bool dfs(vector<vector<char>>& grid,int i,int j,int bal){
    if(bal<0)
    return false;
    if(i==m-1 && j==n-1)
        return bal==0;
    if(dp[i][j][bal]!=-1)
        return dp[i][j][bal];
    if(i+1<m){
        int b=bal;
    if(grid[i+1][j]=='(')
        b++;
    else
        b--;
    if(dfs(grid,i+1,j,b))
        return dp[i][j][bal]=true;
    }
    if(j+1<n){
        int b=bal;
        if(grid[i][j+1]=='(')
            b++;
        else
            b--;
        if(dfs(grid,i,j+1,b))
            return dp[i][j][bal]=true;
    }
    return dp[i][j][bal]=false;
}
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        if((m+n-1)%2!=0)
            return false;
        int bal=0;
        if(grid[0][0]=='(')
            bal++;
        else
            bal--;
        return dfs(grid,0,0,bal);   
    }
};