class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a;

        for(auto &row : grid) {
            for(int v : row) {
                a.push_back(v);
            }
        }

      
        for(int v : a) {
            if((v - a[0]) % x != 0) return -1;
        }

        sort(a.begin(), a.end());

        
        int mid = a[a.size()/2];

        int ans = 0;
        for(int v : a) {
            ans += abs(v - mid) / x;
        }

        return ans;
    }
};