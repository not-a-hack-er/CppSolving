class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // int left=0,right=0;
        // int sum1=0,sum2=0;
        // for(int i=0,j=nums.size()-1;i<nums.size() && j>0;i++,j--){
        //     sum1+=nums[i];
        //     sum2+=nums[j];
        //     if(sum1==sum2){
        //     return 1;break;}
        // }
        // return -1;
        int total = 0;
        for(int x : nums)
        total += x;

        int left = 0;

        for(int i = 0; i < nums.size(); i++) {
        int right = total - left - nums[i];
        if(left == right)
            return i;
        left += nums[i];
}
return -1;
    }
};