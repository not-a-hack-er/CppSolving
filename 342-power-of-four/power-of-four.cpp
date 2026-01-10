class Solution {
public:
    bool isPowerOfFour(int n) {
         if(n==1)
        return true;
        long long si=1;
        while(si<n)
        {
            si*=4;
        }
        if(si==n)
        return true;
        else
        return false;
        
    }
};