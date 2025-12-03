class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void backtrack(int start, int n, int k) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        // Pruning: ensure enough numbers left
        for (int i = start; i <= n - (k - temp.size()) + 1; i++) {
            temp.push_back(i);
            backtrack(i + 1, n, k);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return res;
    }
};