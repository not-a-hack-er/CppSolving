class Solution {
public:
    // int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    //     if (j < 0 || j >= matrix[0].size())
    //         return 1e8;
    //     if (i == 0)
    //         return matrix[0][j];
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int u = matrix[i][j] + f(i - 1, j, matrix, dp);
    //     int ld = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
    //     int rd = matrix[i][j] + f(i - 1, j + 1, matrix, dp);
    //     return dp[i][j] = min(u, min(ld, rd));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 1e8;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int u =dp[i-1][j];
                int ld =1e8,rd=1e8;
                if(j>0)
                    ld=dp[i-1][j-1];
                if(j<m-1)
                    rd=dp[i-1][j+1];
                dp[i][j]=matrix[i][j]+min(u,min(ld,rd));
            }
        }
        for (int j = 0; j < m; j++) {
            maxi = min(maxi, dp[n-1][j]);
        }
        return maxi;
    }
};