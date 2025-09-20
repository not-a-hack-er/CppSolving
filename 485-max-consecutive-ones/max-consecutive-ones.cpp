class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int r=0;
        int c=0;
        for(int n:nums){
            if(n==0){
                c=0;
            }
            else{
                c++;
            }
            if(r<c){
                r=c;
            }
        }
        return r; 
    }
};