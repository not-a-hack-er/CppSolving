class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
       
        queue<pair<pair<int, int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0)
                {
                ans[i][j]=0;
                q.push({{i,j},0});
                vis[i][j]=1;     
                }
                
            }
        }
        
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int r= q.front().first.first;
            int c= q.front().first.second;
            int t= q.front().second;
            
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow =r+drow[i];
                int ncol =c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0)
                {
                    ans[nrow][ncol] = t+1;
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 1;
                }

            }
        }
         /*for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(vis[i][j]!=2 && grid[i][j]==1)
                {
                    return -1;
                }
            }
         }*/
       return ans;
    }
};