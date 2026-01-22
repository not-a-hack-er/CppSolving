class Solution {
public:
void shiftLeft(vector<int>& nums,int idx)
{
    int n=nums.size();
    for(int i=idx;i<n-1;i++)
    {
        nums[i]=nums[i+1];
    }
    nums.pop_back();
}
void mergePairs(vector<int>& nums)
{
    int n=nums.size();
    int min=INT_MAX,minidx=-1;
    for(int i=0;i<n-1;i++)
    {
        int sum=nums[i]+nums[i+1];
        if(sum<min)
        {
            min=sum;
            minidx=i;
        }
    }
    nums[minidx]=min;
    shiftLeft(nums,minidx+1);
}
bool isSorted(vector<int>& nums)
{
    int n=nums.size();
    for(int i=0;i<n-1;i++)
    {
        if(nums[i+1]<nums[i])
        return false;
    }
    return true;
}

    int minimumPairRemoval(vector<int>& nums) {
        int result=0;int n=nums.size();
        while(!isSorted(nums))
        {
            mergePairs(nums);
            result++;
        }
        return result;
    }
};