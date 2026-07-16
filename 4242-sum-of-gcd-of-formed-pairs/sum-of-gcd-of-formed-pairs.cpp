class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> pre;

        int mx = nums[0];

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            pre.push_back(__gcd(nums[i], mx));
        }

        sort(pre.begin(), pre.end());

        long long ans = 0;

        int i = 0, j = n - 1;

        while (i < j) {
            ans += __gcd(pre[i], pre[j]);
            i++;
            j--;
        }

        return ans;
    }
};