class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);

        // max-heap{score, index} we can do this
        priority_queue<pair<int,int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        int rank = 1;
        while (!pq.empty()) {
            auto [sc, idx] = pq.top();
            pq.pop();

            if (rank == 1) 
            ans[idx] = "Gold Medal";
            else if (rank == 2)
            ans[idx] = "Silver Medal";
            else if (rank == 3)
            ans[idx] = "Bronze Medal";
            else 
            ans[idx] = to_string(rank);

            rank++;
        }
        return ans;
    }
};