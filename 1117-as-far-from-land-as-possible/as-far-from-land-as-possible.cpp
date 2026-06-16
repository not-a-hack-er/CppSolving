class Solution {
    private:
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& vis, int delrow[],int delcol[] ) {
       int tr = grid.size();
       
       queue<pair<int,int>> q;
       int ans=-1;
       int l=0,w=0;
       
       for(int i = 0;i<tr;i++)
       {
        for(int j=0;j<tr;j++)
        {
            if(grid[i][j]==1)
            {
                q.push({i,j});
                vis[i][j]=1;
                l++;
            }
            else
                w++;
        }
       }
       if(l==0 || w==0 )
       return -1;
       while(!q.empty())
       {
        
        ans++;

        // int row= it.first;
        // int col = it.second;
        int sz= q.size();

        while(sz--)    
        {
            auto it = q.front();
            q.pop();
            int row= it.first;
            int col = it.second;
            for(int k=0;k<4;k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if(nrow>=0 && nrow < tr && ncol>=0 && ncol<tr && !vis[nrow][ncol])
            {
                vis[nrow][ncol]=1;
                //dist[nrow][ncol]+=1;
                q.push({nrow,ncol});
            }
        }
        }
       }
       return ans;
    }
   
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mi=0,ans=0;
        int delrow[] = {+1,0,-1,0};
        int delcol[] = {0,-1,0,+1};
        vector<vector<int>> vis(n,vector<int>(m,0));
       return  bfs(grid,vis,delrow,delcol);
       
    }
};