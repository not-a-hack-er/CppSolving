class Solution {
public:
    void bfsRecursive(vector<vector<int>>& grid, vector<pair<int, int>>& currentLevel, int dist, int& result) {
        // Base Case: No more nodes to explore
        if (currentLevel.empty()) return;

        vector<pair<int, int>> nextLevel;
        int n = grid.size();

        for (auto& p : currentLevel) {
            int r = p.first;
            int c = p.second;

            // Check if we reached the bottom-right corner
            if (r == n - 1 && c == n - 1) {
                result = dist;
                return;
            }

            // 8 Directions (horizontal, vertical, diagonal)
            int dRow[] = {1, -1, 0, 0, 1, 1, -1, -1};
            int dCol[] = {0, 0, 1, -1, 1, -1, 1, -1};

            for (int i = 0; i < 8; i++) {
                int nr = r + dRow[i];
                int nc = c + dCol[i];

                // If valid neighbor found, mark it visited and add to next level
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; // Mark as visited
                    nextLevel.push_back({nr, nc});
                }
            }
        }

        // Recursive call for the next distance level
        if (result == -1) {
            bfsRecursive(grid, nextLevel, dist + 1, result);
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        int result = -1;
        vector<pair<int, int>> startLevel = {{0, 0}};
        grid[0][0] = 1; // Mark start as visited

        bfsRecursive(grid, startLevel, 1, result);

        return result;
    }
};