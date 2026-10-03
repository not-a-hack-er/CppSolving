class Solution {
public:
    int n;
    queue<pair<int,int>> q;
    int dr[4]={-1,+1,0,0};
    int dc[4]={0,0,-1,1};
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=n || j>=n)
            return;
        if(grid[i][j]!=1)
            return;
        grid[i][j]=2;
        q.push({i,j});
        for(int d=0;d<4;d++){
            dfs(grid,i+dr[d],j+dc[d]);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        bool found=false;
        for(int i=0;i<n && !found;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    found=true;
                    break;
                }
            }
        }
        int dis=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto [i,j]=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int ni=i+dr[d];
                    int nj=j+dc[d];
                    if(ni<0 || nj<0 || ni>=n || nj>=n)
                    continue;
                    if(grid[ni][nj]==1)
                        return dis;
                    if(grid[ni][nj]==0){
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
            dis++;
        }
        return -1;
    }
};