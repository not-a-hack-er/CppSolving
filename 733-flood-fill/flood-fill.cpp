class Solution {
    public:
    void dfs(vector<vector<int>>& ans,vector<vector<int>>& image,int row, int col, int color,int delRow[],int delCol[],int ini)
    {
        ans[row][col] = color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ini && ans[nrow][ncol]!=color)
            {
               dfs(ans,image,nrow,ncol,color,delRow,delCol,ini);
            }
        }
    }
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans= image;
        int ini=image[sr][sc];
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        dfs(ans,image,sr,sc,color,delRow,delCol,ini);

        return ans;
    }
};