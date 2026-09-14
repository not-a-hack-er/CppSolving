class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        long long high=0;
        for(int i=0;i<nums.size();i++)
            high+=nums[i];
        while(low<=high){
            long long mid=(low+high)/2;
            int cnt=1;
            long long sum=0;
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i]>mid){
                    cnt++;
                    sum=nums[i];
                }else{
                sum+=nums[i];
            }
        }
        if(cnt<=k)
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
    }

};