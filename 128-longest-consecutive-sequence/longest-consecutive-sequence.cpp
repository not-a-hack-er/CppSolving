class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        sort(nums.begin(),nums.end());int maxCount=1;
        int n=nums.size();int c=1;
        
       
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) continue; // skip duplicates
            if(nums[i] - nums[i-1] == 1) {
                c++;
            }
            else 
            {
                maxCount=max(maxCount, c);
                c=1;
            }
           
        }
        maxCount = max(maxCount, c);
        return maxCount;
    }
};