class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        bool h=false;
        for(int x:nums){
            xr^=x;
            if(x!=0)
                h=true;
        }
        if(xr!=0)
            return nums.size();
        if(h)
            return nums.size()-1;
        return 0;
    }
};