class Solution {
public:
    int m, n;
    
    void dfs(vector<vector<int>>& h, int i, int j, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        
        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(auto &dir : d) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            
            if(ni>=0 && nj>=0 && ni<m && nj<n &&
               !vis[ni][nj] && h[ni][nj] >= h[i][j]) {
                dfs(h, ni, nj, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            dfs(heights,i,0,pac);
            dfs(heights,i,n-1,atl);
        }
        
        for(int j=0;j<n;j++){
            dfs(heights,0,j,pac);
            dfs(heights,m-1,j,atl);
        }
        
        vector<vector<int>> ans;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};