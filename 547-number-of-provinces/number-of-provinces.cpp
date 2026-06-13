class Solution {
public:
void bfs(int st,vector<vector<int>>& isConnected, vector<int>& vis)
{
    queue<int> q;
    q.push(st);
    vis[st]=1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int nei = 0;nei<isConnected.size(); nei++)
        {
            if(isConnected[node][nei] && !vis[nei])
            {
                vis[nei] = 1;
                q.push(nei);
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> vis(n,0);
    int pro = 0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            pro++;
            bfs(i,isConnected,vis);
        }
    }      
    return pro;
    }
};