class Solution {
public:
    static const int LOG = 17;

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, 0), depth(n, 0);
        vector<int> tin(n), tout(n), pref(n), idx(n, 0);
        vector<vector<int>> up(n, vector<int>(LOG, 0));

        vector<int> st = {0};
        int timer = 0;

        while (!st.empty()) {
            int u = st.back();

            if (idx[u] == 0) {
                tin[u] = ++timer;

                pref[u] = (u == 0 ? 0 : pref[parent[u]]) ^ (1 << (s[u] - 'a'));

                up[u][0] = parent[u];

                for (int j = 1; j < LOG; j++) {
                    up[u][j] = up[up[u][j - 1]][j - 1];
                }
            }

            if (idx[u] == adj[u].size()) {
                tout[u] = timer;
                st.pop_back();
                continue;
            }

            int v = adj[u][idx[u]++];

            if (u != 0 && v == parent[u])
                continue;

            parent[v] = u;
            depth[v] = depth[u] + 1;
            st.push_back(v);
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j))
                    u = up[u][j];
            }

            if (u == v)
                return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }

            return up[u][0];
        };

        vector<int> bit(n + 2, 0);

        auto update = [&](int i, int val) {
            while (i <= n) {
                bit[i] ^= val;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            int ans = 0;

            while (i > 0) {
                ans ^= bit[i];
                i -= i & -i;
            }

            return ans;
        };

        vector<bool> ans;

        for (string q : queries) {
            stringstream ss(q);
            string type;
            int u;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int change = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));

                update(tin[u], change);
                update(tout[u] + 1, change);

                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int mask = pref[u] ^ query(tin[u]) ^ pref[v] ^ query(tin[v]) ^
                           (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};