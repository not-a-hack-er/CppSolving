class Solution {
public:
    int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
        if(i == a.size())
        return b.size() - j; 
        if(j == b.size())
        return a.size() - i; 

        if(dp[i][j] != -1)
        return dp[i][j];

        if(a[i] == b[j]) {
            return dp[i][j] = solve(i+1, j+1, a, b, dp);
        }

        int insertOp = 1 + solve(i, j+1, a, b, dp);
        int deleteOp = 1 + solve(i+1, j, a, b, dp);
        int replaceOp = 1 + solve(i+1, j+1, a, b, dp);

        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, word1, word2, dp);
    }
};