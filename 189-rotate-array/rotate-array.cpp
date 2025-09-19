class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
        k = k % n;  // handle k > n

        // helper function to reverse subarray
        auto reverse = [&](int left, int right) 
        {
            while (left < right)
             {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
    };
     reverse(0, n - 1);
        // Step 2: reverse first k elements
        reverse(0, k - 1);
        // Step 3: reverse rest
        reverse(k, n - 1);
    }
};