class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int minkp=-1;
        int maxkp=-1;
        int culpritidx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                culpritidx=i;
            }
            if(nums[i]==minK)
                minkp=i;
            if(nums[i]==maxK)
                maxkp=i;
            long long smaller=min(minkp,maxkp);
            long long temp=smaller-culpritidx;
            ans+=(temp<=0)?0:temp;
        }
        return ans;
    }
};