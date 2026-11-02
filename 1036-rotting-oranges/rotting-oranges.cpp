class Solution {
public:
    int m, n;
    vector<vector<int>> time;

    void dfs(vector<vector<int>>& grid, int i, int j, int t) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        if (grid[i][j] == 0)
            return;

        if (time[i][j] <= t)
            return;

        time[i][j] = t;

        dfs(grid, i + 1, j, t + 1);
        dfs(grid, i - 1, j, t + 1);
        dfs(grid, i, j + 1, t + 1);
        dfs(grid, i, j - 1, t + 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        time.assign(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    dfs(grid, i, j, 0);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (time[i][j] == INT_MAX)
                        return -1;

                    ans = max(ans, time[i][j]);
                }
            }
        }

        return ans;
    }
};