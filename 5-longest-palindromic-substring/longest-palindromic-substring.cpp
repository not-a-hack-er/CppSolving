class Solution {
public:

    string longestPalindrome(string s) {

        int n = s.size();
        int start = 0, len = 1;

        for(int i = 0; i < n; i++) {

            // Odd length palindrome
            int l = i, r = i;

            while(l >= 0 && r < n && s[l] == s[r]) {

                if(r - l + 1 > len) {
                    len = r - l + 1;
                    start = l;
                }

                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {

                if(r - l + 1 > len) {
                    len = r - l + 1;
                    start = l;
                }

                l--;
                r++;
            }
        }

        return s.substr(start, len);
    }
};