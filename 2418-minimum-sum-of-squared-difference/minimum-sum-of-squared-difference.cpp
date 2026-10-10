class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
          vector<long long> diff;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            diff.push_back(abs((long long)nums1[i] - nums2[i]));
        }

        sort(diff.rbegin(), diff.rend());

        long long k = (long long)k1 + k2;

        for (int i = 0; i < n && k > 0; ) {
            long long x = diff[i];

            int j = i;
            while (j < n && diff[j] == x) {
                j++;
            }
            long long cnt = j;
            long long next = (j < n ? diff[j] : 0);
            long long need = (x - next) * cnt;

            if (need < k) {
               
                k -= need;
                i = j;
            }
            else if (need == k) {
        
                for (int p = 0; p < j; p++) {
                    diff[p] = next;
                }

                k = 0;
            }
            else {
                long long dec = k / cnt;
                long long rem = k % cnt;
                for (int p = 0; p < j; p++) {
                    diff[p] = x - dec;
                }
                for (int p = 0; p < rem; p++) {
                    diff[p]--;
                }

                k = 0;
            }
        }
        if (k > 0) {
            return 0;
        }

        long long ans = 0;

        for (long long x : diff) {
            ans += x * x;
        }

        return ans;
    }
};