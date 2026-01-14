class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, bool> tS;
        unordered_map<int, int> tC;
        for(int i = 0; i < trust.size(); i++) {
            int u = trust[i][0]; 
            int v = trust[i][1];
            
            tS[u] = true;   
            tC[v]++;           
        }
        for(int i = 1; i <= n; i++) {
            if (tS[i] == false && tC[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};