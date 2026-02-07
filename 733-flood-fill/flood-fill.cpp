class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();


        int prev=image[sr][sc];
     if (prev == color)
      return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int x[4]={1,0,-1,0};
        int y[4]={0,1,0,-1};
        while(!q.empty())
        {
            auto[nx,ny]=q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int cx = nx + x[i];
                int cy = ny + y[i];
                if (cx >= 0 && cy >= 0 && cx < m && cy < n && image[cx][cy]==prev)
                {
                    image[cx][cy]=color;
                    q.push({cx,cy});
                }
            }
        }
        return image;
    }
};