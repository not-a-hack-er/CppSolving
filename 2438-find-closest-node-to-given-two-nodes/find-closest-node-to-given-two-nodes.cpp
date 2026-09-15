class Solution {
public:
int n;
    void dfs(vector<int>& edges,int node,vector<int> &dist,vector<bool> &vis){
        vis[node]=true;
        int v=edges[node];
        if(v!=-1 && !vis[v]){
            vis[v]=true;
            dist[v]=1+dist[node];
            dfs(edges,v,dist,vis);
        }
    }
      void bfs(vector<int>& edges,int node,vector<int> &dist){
        queue<int> q;
        dist[node]=0;
        vector<bool> vis(n,false);
        q.push(node);
        vis[node]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            int v=edges[u];
            if(v!=-1 && !vis[v]){
                vis[v]=true;
                dist[v]=1+dist[u];
                q.push(v);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n=edges.size();
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);
        // vector<bool> vis1(n,false);
        // vector<bool> vis2(n,false);
        dist1[node1]=0;
        dist2[node2]=0;
        bfs(edges,node1,dist1);
        bfs(edges,node2,dist2);
        int minNode=-1;
        int mintill=INT_MAX;
        for(int i=0;i<n;i++){
            int maxD=max(dist1[i],dist2[i]);
            if(mintill>maxD){
                mintill=maxD;
                minNode=i;
            }
        }
        return minNode;
    }
};