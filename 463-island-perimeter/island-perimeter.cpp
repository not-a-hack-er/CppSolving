class Solution {
public:
    int bfs(vector<vector<int>>& grid, int sr, int sc) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=true;
        int p=0;
        int dr[] ={1,-1,0,0};
        int dc[] ={0,0,1,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr<0 || nc<0 || nr>=m || nc>=n)
                p++;
                else if(grid[nr][nc]==0)
                p++;
                else if(!vis[nr][nc]){
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
        return p;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return bfs(grid, i, j);
            }
        }
        return 0;
    }
};