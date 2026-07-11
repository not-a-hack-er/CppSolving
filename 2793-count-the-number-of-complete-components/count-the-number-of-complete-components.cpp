class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {

        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        DisjointSet ds(n);
        for (auto &it : edges)
            ds.unionBySize(it[0], it[1]);

        unordered_map<int, int> nodes;
        unordered_map<int, int> edgeCount;

        
        for (int i = 0; i < n; i++) {
            int p = ds.findUPar(i);
            nodes[p]++;
        }
        for (auto &it : edges) {
            int p = ds.findUPar(it[0]);
            edgeCount[p]++;
        }

        int ans = 0;

        for (auto &it : nodes) {

            int parent = it.first;
            int cntNodes = it.second;
            int cntEdges = edgeCount[parent];

            if (cntEdges == (cntNodes * (cntNodes - 1)) / 2)
                ans++;
        }

        return ans;
    }
};