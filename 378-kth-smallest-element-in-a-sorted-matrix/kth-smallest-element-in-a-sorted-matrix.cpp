class Solution {
public:
    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int i = n - 1, j = 0;
        int count = 0;

        while(i >= 0 && j < n) {
            if(matrix[i][j] <= mid) {
                count += (i + 1);
                j++;
            } else {
                i--;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(countLessEqual(matrix, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};