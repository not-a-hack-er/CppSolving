class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minIdx=min_element(nums.begin(),nums.end())-nums.begin();
        int maxIdx=max_element(nums.begin(),nums.end())-nums.begin();
        int left=min(minIdx,maxIdx);
        int right=max(minIdx,maxIdx);
        int ans=min((left+1+n-right),min((right+1),(n-left)));
        return ans;
    }
};