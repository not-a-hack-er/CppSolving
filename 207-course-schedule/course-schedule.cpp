class Solution {
public:
    bool isCyclicDFS(int node,
                     unordered_map<int,int>& visited,
                     unordered_map<int,bool>& dfsVisited,
                     unordered_map<int,list<int>>& adj) {

        visited[node] = 1;
        dfsVisited[node] = 1;

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (isCyclicDFS(neighbour, visited, dfsVisited, adj))
                    return true;
            }
            else if (dfsVisited[neighbour]) {
                return true;
            }
        }

        dfsVisited[node] = 0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);   
        }

        unordered_map<int,int> visited;
        unordered_map<int,bool> dfsVisited;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (isCyclicDFS(i, visited, dfsVisited, adj))
                    return false;
            }
        }
        return true;
    }
};
