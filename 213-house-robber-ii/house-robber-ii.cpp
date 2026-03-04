class Solution {
public:
int solve(vector<int>& nums) { //isme space optimization lga hua h
         int prev2 = 0, prev1 = 0;

        for(int num : nums) {
            int curr = max(prev1, num + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
        return nums[0];

        vector<int> first,second;

        for(int i=0;i<n;i++)
        {
            if(i!=n-1)
            first.push_back(nums[i]);

            if(i!=0)
            second.push_back(nums[i]);
        }

        return max(solve(first),solve(second));
    }
};