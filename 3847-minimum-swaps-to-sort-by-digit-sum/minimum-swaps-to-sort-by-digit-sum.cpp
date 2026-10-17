class Solution {
public:
    int getDigitSum(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> corrected=nums;
        auto lambda=[this](int a,int b){
            int digitSum1= getDigitSum(a);
            int digitSum2= getDigitSum(b);
            if(digitSum1!=digitSum2){
                return digitSum1<digitSum2;
            }
            return a<b;
        };
        sort(corrected.begin(),corrected.end(),lambda);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int swapno=0;
        for(int i=0;i<n;i++){
            int expected=corrected[i];
            int curr=nums[i];
            if(expected==curr)
                continue;
            int idx=mp[expected];
            swap(nums[i],nums[idx]);

            mp[curr]=idx;
            mp[expected]=i;
            swapno++;
        }
        return swapno;
    }
};