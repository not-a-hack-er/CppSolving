class Solution {
public:
    vector<int> searchRange(vector<int>& v, int target) {
          int n = v.size();
        vector<int> ans(2, -1);

        // -------- find first occurrence --------
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (v[mid] == target) {
                ans[0] = mid;
                end = mid - 1;   // move left
            }
            else if (v[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        // -------- find last occurrence --------
        start = 0; end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (v[mid] == target) {
                ans[1] = mid;
                start = mid + 1; // move right
            }
            else if (v[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};