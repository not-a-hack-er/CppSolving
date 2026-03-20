class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        transform(nums.begin(), nums.end(), nums.begin(), [](int x){
            return x * x;
        });

        sort(nums.begin(), nums.end());
        return nums;
    }
};