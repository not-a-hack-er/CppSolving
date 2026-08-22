class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int s=arr[0],ans=arr[0];
        int del=0;
        for(int i=1;i<arr.size();i++){
            int oldS=s;
            s=max(arr[i],s+arr[i]);
            del=max(del+arr[i],oldS);
            ans=max(ans,max(s,del));
        }
        return ans;
    }
};