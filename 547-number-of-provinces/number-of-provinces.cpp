class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        
        visited[city] = true;

        
        for (int n = 0; n < isConnected.size(); n++) {
            
            if (isConnected[city][n] == 1 && !visited[n]) {
                dfs(n, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinceCount = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinceCount++; 
                dfs(i, isConnected, visited); 
            }
        }

        return provinceCount;
    }
};