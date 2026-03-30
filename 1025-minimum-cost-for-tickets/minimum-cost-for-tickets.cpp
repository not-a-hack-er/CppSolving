class Solution {
public:
int solve(int n,vector<int>& days, vector<int>& costs,int i,vector<int>& dp)
{
    if(i>=n)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    int op1 = solve(n, days, costs, i+1,dp)+costs[0];
    int k;
    for(k=i;k<n && days[k]<days[i]+7;k++);
    int op2=solve(n,days,costs,k,dp)+costs[1];
    for(k=i;k<n && days[k]<days[i]+30;k++);
    int op3=solve(n,days,costs,k,dp)+costs[2];
    dp[i]=min(op1,min(op2,op3));
    return dp[i];
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int n=days.size();
       vector<int> dp(n+1,-1);
       return solve(n,days,costs,0,dp); 
    }
};