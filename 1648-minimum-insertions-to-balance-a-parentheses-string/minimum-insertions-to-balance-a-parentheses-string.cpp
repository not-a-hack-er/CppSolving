class Solution {
public:
    int minInsertions(string s) {
        int op = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                op++;
            } else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }
                if (op > 0) {
                    op--;
                } else{
                    ans++;
                }
            }
        }

        ans += 2 * op;

        return ans;
    }
};