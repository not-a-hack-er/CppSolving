class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int even = 1, odd = 0;
        int sum = 0, ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum % 2 == 0) {
                ans = (ans + odd) % mod;
                even++;
            } else {
                ans = (ans + even) % mod;
                odd++;
            }
        }

        return ans;
    }
};