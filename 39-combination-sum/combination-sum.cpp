class Solution {
public:
    void solve(vector<int>& arr, int target, int idx,
               vector<int>& temp, vector<vector<int>>& ans) {

       
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx >= arr.size() || target < 0) return;

      
        temp.push_back(arr[idx]);
        solve(arr, target - arr[idx], idx, temp, ans);
        temp.pop_back();

       
        solve(arr, target, idx + 1, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, 0, temp, ans);
        return ans;
    }
};