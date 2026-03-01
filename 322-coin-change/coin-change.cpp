class Solution {
public:
int solve(vector<int>& coins,int x)
{
    vector<int> dp(x+1,INT_MAX);

    dp[0]=0;

    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<coins.size();j++)
        {
            if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
            {
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
    }
    return dp[x];
}
    int coinChange(vector<int>& coins, int amount) {
      

        int ans=solve(coins,amount);

        if(ans==INT_MAX)
        return -1;

        return ans;
    }
};