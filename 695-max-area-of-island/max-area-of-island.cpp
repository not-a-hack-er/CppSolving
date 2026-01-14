class Solution {
public:
int dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) {
            return 0;
        }
        grid[r][c] = 0;
      return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
    }
   
                
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int area=0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                {
                          
                    int cnt=dfs(grid, i, j);
                    area = max(area,cnt);
                }
            }
           
        }
        return area;
        
    }
};