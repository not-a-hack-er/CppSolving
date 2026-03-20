class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr1=nums[0],curr2=nums[0];
        int ans=nums[0];
        if(nums.size()==1)
        return abs(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            curr1=max(nums[i],curr1+nums[i]);
            curr2=min(nums[i],curr2+nums[i]);

            ans=max(ans,max(curr1,abs(curr2)));

        }
        return ans;
    }
};