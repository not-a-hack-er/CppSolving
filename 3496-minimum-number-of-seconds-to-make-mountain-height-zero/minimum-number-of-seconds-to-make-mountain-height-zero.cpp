class Solution {
public:

    long long maxHeight(long long time, int t) {
        long long l = 0, r = 1e6;

        while (l <= r) {
            long long mid = (l + r) / 2;
            long long need = (long long)t * mid * (mid + 1) / 2;

            if (need <= time)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return r;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long low = 0;
        long long high = 1e18;
        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;

            long long reduced = 0;

            for (int t : workerTimes) {
                reduced += maxHeight(mid, t);
                if (reduced >= mountainHeight) break;
            }

            if (reduced >= mountainHeight) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};