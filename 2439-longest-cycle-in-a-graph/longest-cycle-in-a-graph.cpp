class Solution {
public:
int ans=-1;
void dfs(int cycleLen,int node,vector<int> &current,vector<int> &visited,vector<int>& edges){
    cycleLen++;
    current[node]=cycleLen;
    visited[node]=1;
    int nbr=edges[node];
    if(nbr!=-1){
        if(!visited[nbr]){
            dfs(cycleLen,nbr,current,visited,edges);
        }else if(current[nbr]!=0){
            int currentCycleLen=current[node]-current[nbr]+1;
            ans=max(ans,currentCycleLen);
        }
    }
    current[node]=0;
}
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> visited(n,0);
        vector<int> current(n,0);
        for(int i=0;i<=n-1;i++){
            if(visited[i]!=1)
                dfs(0,i,current,visited,edges);
        }
        return ans;
    }
};