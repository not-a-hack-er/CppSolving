class Solution {
public:
bool solve(int i,int target,vector<int> &nums,vector<vector<int>>& dp){
    if(target==0)
    return true;
    if(i==0)
    return nums[0]==target;
    if(dp[i][target]!=-1)
    return dp[i][target];

    bool nt=solve(i-1,target,nums,dp);

    bool t=false;
    if(nums[i]<=target)
        t=solve(i-1,target-nums[i],nums,dp);

    return dp[i][target] = t || nt;
}
    bool canPartition(vector<int>& nums) {
        int totSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            totSum+=nums[i];
        }
        if(totSum%2==1)
            return false;

        int target=totSum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return solve(n-1,target,nums,dp);
    }
};