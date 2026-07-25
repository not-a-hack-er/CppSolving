class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)
        return 1;
         int total = 0;
        for(int x =0;x<=n;x++)
        total += x;

        int left = 0;

        for(int i = 0; i < n; i++) {
        int right = total - left - i;
        if(left == right)
            return i;
        left += i;
}
return -1;
    }
};