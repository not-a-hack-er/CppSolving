class Solution {
public:
    int maximumProduct(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int ans1=a[n-1]*a[n-2]*a[n-3];
        int ans2=a[0]*a[1]*a[n-1];
        return max(ans1,ans2);
    }
};