class Solution {
public:set<vector<int>> s; // to keep unique combinations

void getAllCombinations(vector<int> &arr, int idx, int target, vector<vector<int>> &ans, vector<int> &combin) {
    if (target == 0) {
        if (s.find(combin) == s.end()) {
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }
    for (int i = idx; i < arr.size(); ++i) {
        if (i > idx && arr[i] == arr[i-1]) continue; // skip duplicates
        if (arr[i] > target) break; // early stopping if sorted
        combin.push_back(arr[i]);
        getAllCombinations(arr, i + 1, target - arr[i], ans, combin);
        combin.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    vector<int> combin;
    sort(arr.begin(), arr.end()); // Make sure to sort here!
    getAllCombinations(arr, 0, target, ans, combin);
    return ans;
}

  
};