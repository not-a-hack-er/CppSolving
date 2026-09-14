class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long count=0,maxNumber=0,i=0,size=nums.size();
        while(maxNumber<n){
            if(i<size && maxNumber+1>=nums[i]){
                maxNumber+=nums[i];
                i++;
            }else{
                count++;
                maxNumber+=(maxNumber+1);
            }
        }
        return count;
    }
};