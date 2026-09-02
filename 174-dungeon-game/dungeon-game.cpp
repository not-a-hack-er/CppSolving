class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& m) {
        // if(m.empty()||m[0].empty())
        //     return 0;
        int n=m.size(),k=m[0].size();
        vector<vector<int>> dp(n,vector<int>(k,-1));
        return rec(0,0,m,dp);
    }
    int rec(int i,int j,vector<vector<int>>& m,vector<vector<int>>& dp){
        if(i>=m.size()||j>=m[0].size())
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        //int health=min(rec(i+1,j,m),rec(i,j+1,m));
        if(i==m.size()-1 && j==m[0].size()-1)
            return dp[i][j]=max(1,1-m[i][j]);
        int health=min(rec(i+1,j,m,dp),rec(i,j+1,m,dp));
        // if(health==INT_MAX)
        //     health=1;
        // int res=0;
        // if(health-m[i][j]>0)
        //     res=health-m[i][j];
        // else
        //     res=1;
        // return res;
        return dp[i][j]=max(1,health-m[i][j]);
    }
};