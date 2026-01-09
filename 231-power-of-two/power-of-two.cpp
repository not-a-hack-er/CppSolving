class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
        return true;
        long long si=2;
        while(si<n)
        {
            si*=2;
        }
        if(si==n)
        return true;
        else
        return false;
    }
};