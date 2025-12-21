class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        auto &pair1 = edges[0];
        auto &pair2 = edges[1];
        if(pair1[0]==pair2[0]||pair1[0]==pair2[1])
        return pair1[0];
        else
        return pair1[1];

        
    }
};