class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(int it:nums){
            mp[it]++;
        }
        for(auto it:mp)
            if(it.second>1)
                ans.push_back(it.first);
        return ans;
    }
};