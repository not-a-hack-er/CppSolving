class Solution {
public:
   
    static bool cmp(string &a, string &b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int x : nums)
        {
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), cmp);

        if (v[0] == "0")
        return "0";

        string ans = "";
        for (string &s : v)
        {
            ans += s;
        }
        return ans;
    }
};
