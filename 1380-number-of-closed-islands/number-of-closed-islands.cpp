class Solution {
public:
    int m,n;
    bool dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n)
            return false;
        
        if(grid[i][j]==1){
            return true;
        }
        grid[i][j] = 1;
        bool lc = dfs(grid,i+1,j);
        bool rc = dfs(grid,i,j+1);
        bool ur= dfs(grid,i-1,j);
        bool dr = dfs(grid,i,j-1);

        return lc && rc && ur && dr;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    if(dfs(grid,i,j)==true)
                        count++;
            }
        }
        return count;
    }
};