class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int l =nums.size();
        vector<int> ans=nums;vector<int> ans1=nums;
         std::sort(ans1.begin(), ans1.end());
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        if(nums==ans||ans1==ans)
        return true;
        else
        return false; 
        
    }
};