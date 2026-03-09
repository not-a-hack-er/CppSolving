class Solution {
public:
    int result = 0;

    void dfs(vector<int>& nums, int val) {
        if (val == 0) {
            result++;
            return;
        }

        for (int i = val; i > 0; i--) {
            swap(nums[i], nums[val]);

            if (nums[val] % val == 0 || val % nums[val] == 0) {
                dfs(nums, val - 1);
            }

            swap(nums[i], nums[val]); // backtrack
        }
    }

    int countArrangement(int n) {
        vector<int> nums(n + 1);

        for (int i = 1; i <= n; i++)
            nums[i] = i;

        dfs(nums, n);

        return result;
    }
};