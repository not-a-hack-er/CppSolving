
// User function Template for C++
https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/0

class Solution {
  public:
    void rotate(vector<int> &arr) {
        int l=arr.size();
        vector<int> ans(l);
        ans=arr;
        int last = arr[l-1];
        for(int i=0;i<l;i++)
        {
            arr[i+1]=ans[i];
        }
        arr[0]=last;
    }
    
};
