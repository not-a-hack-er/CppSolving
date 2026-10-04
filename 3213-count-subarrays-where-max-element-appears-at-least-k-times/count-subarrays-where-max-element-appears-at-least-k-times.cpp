class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxe=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=0;
        long long res=0;
        int count=0;
        while(j<n){
            if(nums[j]==maxe){
                count++;
            }
            while(count>=k){
                res+=n-j;
                if(nums[i]==maxe){
                    count--;
                }
                i++;
            }
            j++;
        }
        return res;
    }
};