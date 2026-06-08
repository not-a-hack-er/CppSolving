class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> less, equal, greater;

        for (int x : nums) {
            if (x < pivot)
            less.push_back(x);
            else if (x == pivot)
            equal.push_back(x);
            else 
            greater.push_back(x);
        }

        vector<int> ans;

        for (int x : less)
         ans.push_back(x);
        for (int x : equal)
         ans.push_back(x);
        for (int x : greater)
         ans.push_back(x);

        return ans;
    }
};