class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.empty())
            return 0;
        long long mx=LONG_MIN;
        long long sum=0;
        for(int x:nums)
            {
                mx=max(mx,(long long)x);
                sum+=x;
            }
        long long n= nums.size();
        return n*mx-sum;
    }
};