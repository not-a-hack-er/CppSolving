class Solution {
public:
    int minimumCost(vector<int>& nums) {
    int cost = nums[0];
        
      
        sort(nums.begin() + 1, nums.end());
        cost += nums[1] + nums[2];
        return cost;   
    }
};