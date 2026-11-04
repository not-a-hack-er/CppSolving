class Solution {
public:
    int solve(vector<int>& prices,int ind,int buy,vector<vector<vector<int>>>& dp,int cap){
        int n=prices.size();
        if(ind==n || cap==0)
            return 0;
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+solve(prices,ind+1,0,dp,cap),solve(prices,ind+1,1,dp,cap));
        }else{
            profit=max(prices[ind]+solve(prices,ind+1,1,dp,cap-1),solve(prices,ind+1,0,dp,cap));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,dp,2);
    }
};