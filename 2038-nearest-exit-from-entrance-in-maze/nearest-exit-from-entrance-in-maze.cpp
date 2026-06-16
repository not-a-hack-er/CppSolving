class Solution {
public:

    int bfs(vector<vector<char>>& maze,
            vector<vector<int>>& vis,
            vector<int>& entrance,
            int delRow[],
            int delCol[])
    {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>> q;

        int sr = entrance[0];
        int sc = entrance[1];

        q.push({sr, sc});
        vis[sr][sc] = 1;

        int steps = 0;

        while(!q.empty())
        {
            int sz = q.size();

            while(sz--)
            {
                auto it = q.front();
                q.pop();

                int row = it.first;
                int col = it.second;

                // Exit found
                if((row == 0 || row == n-1 ||
                    col == 0 || col == m-1) &&
                   !(row == sr && col == sc))
                {
                    return steps;
                }

                for(int k = 0; k < 4; k++)
                {
                    int nrow = row + delRow[k];
                    int ncol = col + delCol[k];

                    if(nrow >= 0 && nrow < n &&
                       ncol >= 0 && ncol < m &&
                       !vis[nrow][ncol] &&
                       maze[nrow][ncol] == '.')
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }

            steps++;
        }

        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        return bfs(maze, vis, entrance, delRow, delCol);
    }
};