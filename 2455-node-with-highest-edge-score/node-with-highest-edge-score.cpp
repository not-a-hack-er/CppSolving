class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long> escore(n,0);
        for(int i=0;i<n;i++)
            escore[edges[i]] += i;
        int idx=0;
        long long score=escore[0];
        for(int i=0;i<n;i++){
            if(escore[i]>score){
                score=escore[i];
                idx=i;}
        }
        return idx;
    }
};