class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
               vector<int> ans;
        
        for(int x : nums) {
            vector<int> temp;
            while(x > 0) {
                temp.push_back(x % 10);
                x /= 10;
            }
            reverse(temp.begin(), temp.end());
            for(int d : temp) {       
                ans.push_back(d);
            }
        } 
        return ans;
    }
};