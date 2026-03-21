class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int MOD = 1e9 + 7;

        long long curr = 0, best = 0;

        for(int i = 0; i < arr.size() * min(2, k); i++) {
            curr = max((long long)arr[i % arr.size()], curr + arr[i % arr.size()]);
            best = max(best, curr);
        }

        long long total = accumulate(arr.begin(), arr.end(), 0LL);

        if(k > 2 && total > 0) {
            best += (k - 2) * total;
        }

        return best % MOD;
    }
};