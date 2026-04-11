class Solution {
public:
int solve(string text1, string text2,int i,int j,vector<vector<int>>& dp)
{
    int ans=0;
    if(i==text1.size())
        return 0;
    if(j==text2.size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(text1[i]==text2[j])
         ans=1+solve(text1,text2,i+1,j+1,dp);
    else
    {
        ans=max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
    }
    return dp[i][j]=ans;
}
int solveTab(string a,string b)
{
    vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1));
    for(int i=a.size()-1;i>=0;i--)
    {
        for(int j=b.size()-1;j>=0;j--)
        {
            int ans=0;
            if(a[i]==b[j])
            {
                ans=1+dp[i+1][j+1];
            }
            else
            {
                ans=max(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][0];
}
int solvesp(string a,string b)
{
    vector<int> curr(b.size()+1,0);
    vector<int> next(b.size()+1,0);
    for(int i=a.size()-1;i>=0;i--)
    {
        for(int j=b.size()-1;j>=0;j--)
        {
            int ans=0;
            if(a[i]==b[j])
            {
                ans=1+next[j+1];
            }
            else
            {
                ans=max(next[j],curr[j+1]);
            }
           curr[j]=ans;
        }
        next=curr;
    }
    return next[0];
}
    int longestCommonSubsequence(string text1, string text2) {
        //vector<vector<int>> dp(text1.size(),vector<int> (text2.size(),-1));
        return solvesp(text1,text2);
    }
};