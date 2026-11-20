class Solution {
public:
    int dp[21][1001];
    int countSubsetSum(int n,int sum,vector<int>& nums){
        if(n==0)
            return (sum==0)?1:0;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        int skip=countSubsetSum(n-1,sum,nums);
        int take=0;
        if(nums[n-1]<=sum)
            take=countSubsetSum(n-1,sum-nums[n-1],nums);
        return dp[n][sum]=(skip+take);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        memset(dp, -1, sizeof(dp));
        target=abs(target);
        for(int &x:nums){
            sum+=x;
        }
        if((sum+target)%2 !=0)
            return 0;
        int s1=(sum+target)/2;
        return countSubsetSum(n,s1,nums);
    }
};