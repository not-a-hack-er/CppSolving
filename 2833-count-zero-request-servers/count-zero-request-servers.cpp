class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        vector<int> freq(n + 1, 0);

        int left = 0, right = 0, cnt = 0;

        for (auto it : q) {
            int start = it.first - x;
            int end = it.first;

            while (right < logs.size() && logs[right][1] <= end) {
                int id = logs[right][0];

                if (freq[id] == 0)
                    cnt++;

                freq[id]++;
                right++;
            }

            while (left < right && logs[left][1] < start) {
                int id = logs[left][0];

                freq[id]--;

                if (freq[id] == 0)
                    cnt--;

                left++;
            }

            ans[it.second] = n - cnt;
        }
        //sort(ans.begin(), ans.end());
        return ans;
    }
};