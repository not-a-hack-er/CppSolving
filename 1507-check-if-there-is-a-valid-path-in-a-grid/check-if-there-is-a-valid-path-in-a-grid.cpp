class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if(x == n-1 && y == m-1) return true;

            int type = grid[x][y];

        
            if((type==1 || type==3 || type==5) && y-1>=0) {
                int nt = grid[x][y-1];
                if((nt==1 || nt==4 || nt==6) && !vis[x][y-1]) {
                    vis[x][y-1] = 1;
                    q.push({x,y-1});
                }
            }

                   if((type==1 || type==4 || type==6) && y+1<m) {
                int nt = grid[x][y+1];
                if((nt==1 || nt==3 || nt==5) && !vis[x][y+1]) {
                    vis[x][y+1] = 1;
                    q.push({x,y+1});
                }
            }
            if((type==2 || type==5 || type==6) && x-1>=0) {
                int nt = grid[x-1][y];
                if((nt==2 || nt==3 || nt==4) && !vis[x-1][y]) {
                    vis[x-1][y] = 1;
                    q.push({x-1,y});
                }
            }

       
            if((type==2 || type==3 || type==4) && x+1<n) {
                int nt = grid[x+1][y];
                if((nt==2 || nt==5 || nt==6) && !vis[x+1][y]) {
                    vis[x+1][y] = 1;
                    q.push({x+1,y});
                }
            }
        }

        return false;
    }
};