class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s=0;
        for(int n:nums){
            s^=n;
        }
        return s;
    }
};