class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
     sort(nums.begin(),nums.end(),[](int &a,int&b){
        return abs(a)>abs(b);
     });
     int n=nums.size();
     long long res=0;
     int i=0;
     while(i<(n+1)/2){
        res+=(long long)nums[i]*nums[i];
        i++;
     }
     while(i<n){
        res-=(long long)nums[i]*nums[i];
        i++;
     }
     return res;
    }
};