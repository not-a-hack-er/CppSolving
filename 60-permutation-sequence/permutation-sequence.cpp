class Solution {
public:
   
        string getPermutation(int n, int k) {
    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(i);

    while (--k)
        next_permutation(v.begin(), v.end());

    string ans;
    for (int x : v) ans += to_string(x);
    return ans;
}

    
};