class Solution {
public:
    int calcSum(int n){
        int s=0;
        while(n>0){
            int rem=n%10;
            s+=rem;
            n/=10;
        }
        return s;
    }
    int calcMul(int n){
        int m=1;
        while(n>0){
            int rem=n%10;
            m*=rem;
            n/=10;
        }
        return m;
    }
    bool checkDivisibility(int n) {
        int rs=calcSum(n);
        int rm=calcMul(n);
        if(n%(rs+rm)==0)
            return true;
        else
            return false;
    }
};