class Solution {
public:
class DSU
{
    public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n)
    {
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        rank.resize(n,0);
    }
    int find(int x){
        if(parent[x]==x)
        return x;
        return parent[x]=find(parent[x]);
    }
    bool unite(int x,int y)
    {
        int px=find(x);
        int py=find(y);

        if(px==py)
        return false;

        if(rank[px]<rank[py])
        {
            parent[px]=py;
        }
        else if(rank[px]>rank[py])
        {
            parent[py]=px;
        }
        else
        {
            parent[py]=px;
            rank[px]++;
        }
        return true;
    }
};

int getMSTWeight(int n, vector<vector<int>>& edges, int exclude_edge_idx, int include_edge_idx)
{
    DSU dsu(n);
    int mstWt=0;
    int edgeCount=0;

    if(include_edge_idx!=-1)
    {
        int u=edges[include_edge_idx][0];
        int v=edges[include_edge_idx][1];
        int wt=edges[include_edge_idx][2];

        dsu.unite(u,v);
        mstWt+=wt;
        edgeCount++;
    }
    for(int i=0;i<edges.size();i++)
    {
        if(i==exclude_edge_idx) 
        continue;
        if(i==include_edge_idx)
        continue;

        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];

        if(dsu.unite(u,v))
        {
            mstWt+=wt;
            edgeCount++;
        }
    }
    if(edgeCount==n-1)
    return mstWt;

    return INT_MAX;
}
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> sortedEdges=edges;

        for(int i=0;i<edges.size();i++)
        sortedEdges[i].push_back(i);
        
        sort(sortedEdges.begin(),sortedEdges.end(),[](vector<int> &b,vector<int> &a)
        {
            return b[2]<a[2];
        });

        int originalWt=getMSTWeight(n,sortedEdges,-1,-1);

        vector<int> critical;
        vector<int> pseudo;

        for(int i=0;i<sortedEdges.size();i++)
        {
            int ogIdx=sortedEdges[i][3];

            int wtExcluding = getMSTWeight(n,sortedEdges,i,-1);

            if(wtExcluding>originalWt)
            {
                critical.push_back(ogIdx);
            }
            else
            {
                int wtIncluding=getMSTWeight(n,sortedEdges,-1,i);

                if(wtIncluding==originalWt)
                pseudo.push_back(ogIdx);
            }
        }
        return {critical,pseudo};
    }
};