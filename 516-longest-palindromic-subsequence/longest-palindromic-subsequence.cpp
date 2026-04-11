class Solution {
public:
int solve(string &s,int i,int j,vector<vector<int>> &dp)
{
    if(i == j) 
        return 1;
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==s[j])
        return 2+solve(s,i+1,j-1,dp);
    return dp[i][j]=max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
}
    int longestPalindromeSubseq(string s) {
        int k=s.size();
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return solve(s,0,k-1,dp);
    }
};