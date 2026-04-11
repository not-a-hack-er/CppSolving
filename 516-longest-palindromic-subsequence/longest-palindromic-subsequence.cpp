class Solution {
public:
int solve(string &s)
{
     int n = s.size();
     vector<int> dp(n, 0);
        for(int i = n-1; i >= 0; i--) {
            int prev = 0;   
            dp[i] = 1;      
            for(int j = i+1; j < n; j++) {
                int temp = dp[j];  

                if(s[i] == s[j]) {
                    dp[j] = 2 + prev;
                } else {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prev = temp;
            }
        }

        return dp[n-1];
}
    int longestPalindromeSubseq(string s) {
        // int k=s.size();
        // vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return solve(s);
    }
};