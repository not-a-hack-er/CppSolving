class Solution {
public:
    int lengthOfLastWord(string s) {
         int n = s.size(), len = 0, i = n - 1;
        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') i--;
        // Count length of last word
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }
        return len;
    }
};