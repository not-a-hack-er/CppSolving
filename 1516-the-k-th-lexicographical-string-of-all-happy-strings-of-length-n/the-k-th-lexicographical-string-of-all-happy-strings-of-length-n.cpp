class Solution {
public:
    void dfs(string &curr, int n, int &k, string &ans) {
        if(curr.size() == n) {
            k--;
            if(k == 0) ans = curr;
            return;
        }

        for(char c : {'a','b','c'}) {
            if(curr.empty() || curr.back() != c) {
                curr.push_back(c);
                dfs(curr, n, k, ans);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr = "", ans = "";
        dfs(curr, n, k, ans);
        return ans;
    }
};