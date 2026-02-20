class Solution {
public:
    int minMST(vector<vector<pair<int,int>>> &adj,int V)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});

        vector<bool> inMST(V,false);

        int sum=0;

        while(!pq.empty())
        {
            auto p=pq.top();
            

            int wt=p.first;
            int node=p.second;

            pq.pop();

            if(inMST[node]==true)
            continue;

            inMST[node]=true;
            sum+=wt;

            for(auto &tmp : adj[node])
            {

                int neigh = tmp.first;
                int neigh_wt=tmp.second;

                if(inMST[neigh]==false)
                {
                    pq.push({neigh_wt,neigh});
                }
            }
        }
        return sum;
    }


    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();

        vector<vector<pair<int,int>>> adj(V);

        for(int i=0;i<V;i++)
        {
            for(int j=i+1;j<V;j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int d=abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({j,d});
                adj[j].push_back({i,d});

            }
        }
        return minMST(adj,V);
    }
};