class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int k=0;
        for(int i=1;i<=n;i++)
        {
            while (k + 1 < n && nums[k] == nums[k + 1]) {
                k++;
            }
            if (k < n && nums[k] == i) {
                k++;
                } else {
                ans.push_back(i);
            }

            
        }
        return ans;
    }
};