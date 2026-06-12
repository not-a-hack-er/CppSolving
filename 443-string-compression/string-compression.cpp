class Solution {
public:
    int compress(vector<char>& chars) {

        if(chars.size() == 1) return 1;

        int count = 1;
        string ans = "";

        for(int i = 1; i < chars.size(); i++) {

            if(chars[i] == chars[i - 1]) {
                count++;
            }
            else {

                ans += chars[i - 1];

                if(count > 1) {
                    ans += to_string(count);
                }

                count = 1;
            }
        }

        ans += chars.back();

        if(count > 1) {
            ans += to_string(count);
        }

        for(int i = 0; i < ans.size(); i++) {
            chars[i] = ans[i];
        }

        return ans.size();
    }
};