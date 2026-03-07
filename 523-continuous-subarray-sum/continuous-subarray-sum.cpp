class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int prefSum = 0;

        unordered_map<int,int> firstOcc;
        firstOcc[0] = 0;

        for(int i = 0; i < n; i++)
        {
            prefSum = (prefSum + nums[i]) % k;

            if(firstOcc.find(prefSum) != firstOcc.end())
            {
                if((i + 1) - firstOcc[prefSum] >= 2)
                    return true;
            }
            else
            {
                firstOcc[prefSum] = i + 1;
            }
        }

        return false;
    }
};