class Solution {
public:

    bool possible(vector<int> &arr, int day, int m, int k) {
        int cnt = 0;
        int noOfB = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= day) {
                cnt++;
            } 
            else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }

        noOfB += (cnt / k);

        return noOfB >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {

        long long val = 1LL * m * k;
        if(val > arr.size()) return -1;

        int mini = INT_MAX, maxi = INT_MIN;

        for(int i = 0; i < arr.size(); i++) {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }

        int low = mini, high = maxi;
        int ans = -1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(possible(arr, mid, m, k)) {
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