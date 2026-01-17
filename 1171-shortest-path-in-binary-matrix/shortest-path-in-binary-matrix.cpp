class Solution {
public:
    void bfsRecursive(vector<vector<int>>& grid, vector<pair<int, int>>& currentLevel, int dist, int& result) {
        
        if (currentLevel.empty()) return;

        vector<pair<int, int>> nextLevel;
        int n = grid.size();

        for (auto& p : currentLevel) {
            int r = p.first;
            int c = p.second;
            if (r == n - 1 && c == n - 1) {
                result = dist;
                return;
            }
            int dRow[] = {1, -1, 0, 0, 1, 1, -1, -1};
            int dCol[] = {0, 0, 1, -1, 1, -1, 1, -1};

            for (int i = 0; i < 8; i++) {
                int nr = r + dRow[i];
                int nc = c + dCol[i];

             
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    nextLevel.push_back({nr, nc});
                }
            }
        }

        if (result == -1) {
            bfsRecursive(grid, nextLevel, dist + 1, result);
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        int result = -1;
        vector<pair<int, int>> startLevel = {{0, 0}};
        grid[0][0] = 1;

        bfsRecursive(grid, startLevel, 1, result);

        return result;
    }
};