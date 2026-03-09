class Solution {
public:
    int result = 0;

    void dfs(vector<int>& nums, int val, int n) {
        if(val > n) {
            result++;
            return;
        }

        for(int i = 1; i <= n; i++) {
            if(nums[i] == 0 && (val % i == 0 || i % val == 0)) {
                nums[i] = val;
                dfs(nums, val + 1, n);
                nums[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> nums(n + 1, 0);
        dfs(nums, 1, n);
        return result;
    }
};