class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            while (nums[i] >(long long) k * nums[start]) {
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }

        return n - maxLen;
    }
};
