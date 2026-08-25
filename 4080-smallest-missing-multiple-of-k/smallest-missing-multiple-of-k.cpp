class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums)
            mp[x]++;
        int j=k;
        while(mp.count(j))
            j+=k;
        return j;
    }
};