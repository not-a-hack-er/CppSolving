class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> sm(n);
        sm[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            {
                sm[i]=min(nums[i],sm[i+1]);
            }
        int pm=nums[0];
        for(int i=0;i<n;i++)
            {
                pm=max(pm,nums[i]);
                if(pm-sm[i]<=k)
                    return i;
            }
        return -1;
    }
};