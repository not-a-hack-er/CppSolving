class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            double p=succProb[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        vector<double> prob(n,0.0);

        priority_queue<pair<double,int>> pq;

        prob[start_node] = 1.0;
        pq.push({1.0,start_node});

        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();

            double currProb=top.first;
            int node=top.second;

            if(node==end_node)
            return currProb;

            for(auto nei:adj[node])
            {
                int nextNode = nei.first;
                double edgeProb = nei.second;

                if (currProb * edgeProb > prob[nextNode])
                {
                    prob[nextNode] = currProb * edgeProb;
                    pq.push({prob[nextNode], nextNode});
                }
            }
        }
    return 0.0;
    }
};