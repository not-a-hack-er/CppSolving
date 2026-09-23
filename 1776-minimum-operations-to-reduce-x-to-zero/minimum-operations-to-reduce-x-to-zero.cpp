class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        long long total=0;
        for(int i=0;i<n;i++)
            total+=nums[i];
        long long target=total-x;
        if(target<0)
            return -1;
        if(target==0)
            return n;
            int i=0;
            long long sum=0;
            int maxi=-1;
            for(int j=0;j<n;j++){
                sum+=nums[j];
                while(i<=j && sum>target){
                    sum-=nums[i];
                    i++;
                }
                if(sum==target)
                    maxi=max(maxi,j-i+1);
            }
            if(maxi==-1)
                return -1;
            return n-maxi;
    }
};