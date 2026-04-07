class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i=0, e= numbers.size()-1;
        while(i<=e)
        {
            if(numbers[i]+numbers[e]==target)
            {
                ans.push_back(i+1);
                ans.push_back(e+1);
                return ans;
            }
            else if(numbers[i]+numbers[e]>target)
            {
                e--;
            }
            else if(numbers[i]+numbers[e]<target)
            {
                i++;
            }
            else
            {
                return ans;
            }
        }
            return ans;

        }
    
};