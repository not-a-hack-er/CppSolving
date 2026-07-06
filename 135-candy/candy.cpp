class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        int up = 0;
        int down = 0;
        int oldSlope = 0;
        int ans = 1;
        for (int i = 1; i < n; i++) {

            int newSlope = 0;

            if (ratings[i] > ratings[i - 1])
                newSlope = 1;
            else if (ratings[i] < ratings[i - 1])
                newSlope = -1;
            if ((oldSlope > 0 && newSlope == 0) ||
                (oldSlope < 0 && newSlope >= 0)) {
                ans += up*(up+1)/2;
                ans += down*(down+1)/2;
                ans += max(up,down);
                up = 0;
                down = 0;
            }
            if (newSlope > 0)
                up++;
            else if (newSlope < 0)
                down++;
            else
                ans++;
            oldSlope = newSlope;
        }

        ans +=up * (up + 1) / 2;
        ans +=down * (down+1)/2;
        ans +=max(up,down);
        return ans;
    }
};