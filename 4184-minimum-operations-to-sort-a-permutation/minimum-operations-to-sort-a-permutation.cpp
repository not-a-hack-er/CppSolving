class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int p = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool increasing = true, decreasing = true;

        for (int i = 0; i < n; i++) {
            int value = nums[(p + i) % n];

            if (value != i)
                increasing = false;

            if (value != (n - i) % n)
                decreasing = false;
        }

        int ans = INT_MAX;

        if (increasing) {
            ans = min(ans, p);
            ans = min(ans, n - p + 2);
        }

        if (decreasing) {
            ans = min(ans, n - p);
            ans = min(ans, (p + 1) % n + 1);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};