class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
        vector<int> ans(n, 1);

       
        int lP = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = lP;
            lP*= nums[i];
        }

        
        int rP = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= rP;
            rP *= nums[i];
        }

        return ans;
        
    }
};