class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d != dist[u][cnt])
                continue;

            if (u == n - 1)
                return d;

            for (auto it : adj[u]) {

                int v = it.first;
                int w = it.second;

                int newCnt = 1;

                if (labels[u] == labels[v])
                    newCnt = cnt + 1;

                if (newCnt > k)
                    continue;

                if (d + w < dist[v][newCnt]) {
                    dist[v][newCnt] = d + w;
                    pq.push({d + w, v, newCnt});
                }
            }
        }

        return -1;
    }
};