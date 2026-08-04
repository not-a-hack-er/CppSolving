class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int mn=*min_element(nums.begin(),nums.end());
        int mm=*max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=mn;i<mm;i++){
            if(i==nums[j]){
                j++;
                continue;
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};