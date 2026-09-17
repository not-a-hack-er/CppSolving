class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int  n=arr.size();
        int i=0,j=0;
        int currSum=0;
        vector<int> minBest(n,INT_MAX);
        int bestMin=INT_MAX;
        int res=INT_MAX;
        while(j<n){
            currSum+=arr[j];
            while(i<j && currSum>target){
                currSum-=arr[i];
                i++;
            }
            if(currSum==target){
                int len=j-i+1;
                if(i>0 && minBest[i-1]!=INT_MAX){
                    res=min(res,len+minBest[i-1]);
                }
                bestMin=min(bestMin,len);
            }
            minBest[j]=bestMin;
            j++;
        }
        return res==INT_MAX?-1:res;
    }
};