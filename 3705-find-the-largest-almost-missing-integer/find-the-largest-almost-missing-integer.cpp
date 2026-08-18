class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> cnt(51,0);
        for(int x=0;x<=50;x++){
            for(int i=0;i<=n-k;i++){
                bool f=false;
                for(int j=i;j<i+k;j++){
                    if(nums[j]==x){
                        f=true;
                        break;
                    }
                }
                if(f)
                    cnt[x]++;
            }
        }
        for(int x=50;x>=0;x--){
            if(cnt[x]==1)
                return x;
        }
        return -1;
    }
};