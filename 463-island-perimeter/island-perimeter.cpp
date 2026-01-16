class Solution {

public:
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return 1;
        }
        
        if (grid[r][c] == 0) {
            return 1;
        }
        if (visited[r][c]) {
            return 0;
        }
        visited[r][c] = true;
        int perimeter = 0;
        perimeter += dfs(grid, r + 1, c, visited);
        perimeter += dfs(grid, r - 1, c, visited);
        perimeter += dfs(grid, r, c + 1, visited);
        perimeter += dfs(grid, r, c - 1, visited);
        
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
    
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j, visited);
                }
            }
        }
        return 0;
    
    }
};