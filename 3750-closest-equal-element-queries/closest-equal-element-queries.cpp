class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;

        for(int q : queries) {
            auto &v = mp[nums[q]];

            if(v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();

            int best = INT_MAX;
            int next = v[(pos + 1) % v.size()];
            int diff1 = abs(next - q);
            best = min(best, min(diff1, n - diff1));
            int prev = v[(pos - 1 + v.size()) % v.size()];
            int diff2 = abs(prev - q);
            best = min(best, min(diff2, n - diff2));

            ans.push_back(best);
        }

        return ans;
    }
};