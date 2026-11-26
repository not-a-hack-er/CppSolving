class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total = 0;

        for (int i = 0; i < n; i++) {
            total += cardPoints[i];
        }

        int window = n - k;
        int sum = 0;

        for (int i = 0; i < window; i++) {
            sum += cardPoints[i];
        }

        int mini = sum;

        int i = 0, j = window;

        while (j < n) {
            sum -= cardPoints[i];
            sum += cardPoints[j];

            mini = min(mini, sum);

            i++;
            j++;
        }

        return total - mini;
    }
};