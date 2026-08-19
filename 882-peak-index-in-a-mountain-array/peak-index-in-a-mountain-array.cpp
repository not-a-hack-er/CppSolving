class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxi=*max_element(arr.begin(),arr.end());
        // int st=0,end=nums.size()-1;
        // int mid=(st+end)/2;
        // while(st<=end){
        //     if(arr[mid]==maxi)
        //         return mid;
        //     else if(arr[mid]>)
        // }
        int k=find(arr.begin(), arr.end(), maxi)- arr.begin();
        return k;

    }
};