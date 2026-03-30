class Solution {
public:

int solve2(int n, vector<int>& days, vector<int>& costs)
{
    vector<int> dp(n+1, 0);

    for(int j = n-1; j >= 0; j--)
    {
        int op1 = dp[j+1] + costs[0];

        int k;
        for(k = j; k < n && days[k] < days[j] + 7; k++);
        int op2 = dp[k] + costs[1];

        for(k = j; k < n && days[k] < days[j] + 30; k++);
        int op3 = dp[k] + costs[2];

        dp[j] = min(op1, min(op2, op3));
    }
    return dp[0];
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int n=days.size();
       //vector<int> dp(n+1,-1);
       return solve2(n,days,costs); 
    }
};