class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l= nums.size(); vector<int> ans(l);
         k = k % l;
        for(int i=0;i<l;i++)
        {
            
            ans[(i+k)%l]=nums[i];

        }
        nums=ans;
       for (int x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }
};