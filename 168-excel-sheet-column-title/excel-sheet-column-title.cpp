class Solution {
public:
    string convertToTitle(int columnNumber) {
         string ans = "";
        int n=columnNumber;
        while(n > 0) {
            n--;
            char ch = 'A' + (n % 26);
            ans += ch;
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};