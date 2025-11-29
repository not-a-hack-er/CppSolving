class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
         vector<vector<int>> g(n);
       for (auto &e : edges) {

            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int ans = 0;

        function<long long(int,int)> dfs = [&](int u, int parent) -> long long {
            long long sum = values[u];

            for (int v : g[u]) {
                if (v == parent) continue;
                sum += dfs(v, u);
            }

            if (sum % k == 0) {
                ans++;           // this subtree forms a separate component
                return 0;        // cut here; contribute nothing upward
            }
            return sum;          // pass partial sum to parent
        };

        dfs(0, -1);
        return ans;
    
    }
    
};