class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int left=0;
        while(left+1<n && arr[left]<=arr[left+1])
            left++;
        if(left==n-1)
            return 0;
        int right=n-1;
        while(right>0 && arr[right]>=arr[right-1])
            right--;
        int ans=min(n-left-1,right);
        // while(right<n && left>=0){
        //     if(arr[left]<=arr[right]){
        //         ans=min(right-left-1,ans);
        //         left--;
        //     }else{
        //         right++;
        //     }
        // }
        int j=right;
        for(int i=0;i<=left;i++){
            while(j<n && arr[i]>arr[j])
                j++;
            if(j==n)
                break;
            ans=min(ans,j-i-1);
        }
        return ans;
    }
};