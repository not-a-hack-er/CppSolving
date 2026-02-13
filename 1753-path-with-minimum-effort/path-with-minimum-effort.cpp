class Solution {
public:
    
    bool canReach(vector<vector<int>>& heights, int maxEffort) {
        
        int m = heights.size();
        int n = heights[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        q.push({0,0});
        vis[0][0] = 1;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        while(!q.empty()) {
            
            auto [x,y] = q.front();
            q.pop();
            
            if(x == m-1 && y == n-1)
                return true;
            
            for(int i=0;i<4;i++) {
                
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny]) {
                    
                    int diff = abs(heights[nx][ny] - heights[x][y]);
                    
                    if(diff <= maxEffort) {
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        return false;
    }
    
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int low = 0;
        int high = 1e6;
        int ans = 0;
        
        while(low <= high) {
            
            int mid = (low + high) / 2;
            
            if(canReach(heights, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
