class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        int len = nums[0].size();
        vector<int> ans;

        for (auto &q : queries) {
            
            int k = q[0];
            int trim = q[1];

            
            vector<int> temp(n);
            for (int i = 0; i < n; i++) {
                temp[i] = i;
            }

            
            sort(temp.begin(), temp.end(), [&](int a, int b) {

                for (int i = len - trim; i < len; i++) {
                    if (nums[a][i] != nums[b][i])
                        return nums[a][i] < nums[b][i];
                }

               
                return a < b;
            });

            ans.push_back(temp[k - 1]);
        }

        return ans;
    }
};
