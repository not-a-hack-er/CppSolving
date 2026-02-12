class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i:times)
        {
            int u=i[0];
            int v=i[1];
            int w=i[2];
            adj[u].push_back({v,w});
        }
        vector<int> distance(n+1,INT_MAX);

        set<pair<int,int>> st;

        distance[k]=0;

        st.insert({0,k});

        while(!st.empty())
        {
            auto top = *(st.begin());
            int nodeDis = top.first;
            int node = top.second;
            st.erase(st.begin());

            for(auto nei : adj[node])
            {
                int neiNode = nei.first;
                int wt = nei.second;

                if(wt + nodeDis < distance[neiNode])
                {
                    auto record = st.find({distance[neiNode],neiNode});
                    if(record!=st.end())
                    {
                        st.erase(record);
                    }
                    distance[neiNode] = nodeDis + wt;
                    st.insert({distance[neiNode],neiNode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (distance[i] == INT_MAX) 
            return -1; 
            ans = max(ans, distance[i]);
        }

        return ans;

    }
};