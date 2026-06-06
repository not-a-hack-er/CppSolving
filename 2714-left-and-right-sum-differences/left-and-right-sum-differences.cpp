class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n = nums.size();

        int rightSum = 0;
        for (int x : nums) rightSum += x;

        int leftSum = 0;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            rightSum -= nums[i];

            ans[i] = abs(leftSum - rightSum);

            leftSum += nums[i];
        }

        return ans;
    }
};