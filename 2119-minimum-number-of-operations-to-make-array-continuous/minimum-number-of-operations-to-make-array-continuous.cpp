class Solution {
public:
    bool isUnique(vector<int>& nums)
    {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        for(auto j:mp){
            if(j.second>1)
                return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        // int maxE=*max_element(nums.begin(),nums.end());
        // int miniE=*min_element(nums.begin(),nums.end());
        // nums.erase(unique(nums.begin(),nums.end()),nums.end());
        // if(isUnique(nums) && (maxE-miniE)==n-1)
        // return 0;
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int count=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            while(j<nums.size() && nums[j]-nums[i]<=n-1)
            j++;
            count=max(count,j-i);
        }
        return n-count;
    }
};