class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> a=nums;
        sort(a.begin(),a.end());
        vector<vector<int>> g;
        map<int,int> mp;
        for(int n:a){
            if(g.empty()||abs(n-g.back().back())>limit)
                g.push_back({});
            g.back().push_back(n);
            mp[n]=g.size()-1;
        }
        vector<int> pos(g.size(),0);
        vector<int> ans;
        for(int n:nums){
            int j=mp[n];
            ans.push_back(g[j][pos[j]]);
            pos[j]++;
        }
        return ans;
    }
};