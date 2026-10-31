class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                vector<int> v;

                for (int k = 0; k < n; k++) {
                    if (k < i || k > j) {
                        v.push_back(nums[k]);
                    }
                }

                bool flag = true;

                for (int k = 1; k < v.size(); k++) {
                    if (v[k] <= v[k - 1]) {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                    ans++;
            }
        }

        return ans;
    }
};