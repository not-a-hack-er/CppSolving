class Solution {
public:
    int rob(vector<int>& nums) { //isme space optimization lga hua h
         int prev2 = 0, prev1 = 0;

        for(int num : nums) {
            int curr = max(prev1, num + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};