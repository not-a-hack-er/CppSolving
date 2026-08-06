class Solution {
public:
    int product(int x){
        int mul=1;
       while(x>0){
    mul*=x%10;
    x/=10;
}
return mul;
}
    int smallestNumber(int n, int t) {
        while(true){
        if(product(n)%t==0)
        return n;
         n++;
}
    }
};