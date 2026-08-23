class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
        return 0;
        vector<bool> arr(n,false);
        for(int i = 4; i < n; i += 2)
            arr[i] = true;
        int l=sqrt(n);
        for(int i=3;i<=l;i+=2){
            if(arr[i]==false){
                for(int j=i*i;j<n;j+=2*i){
                    arr[j]=true;
                }
            }
        }
        int c=1;
        for(int i=3;i<n;i+=2){
            if(arr[i]==false)
                c++;
        }
        return c;
    }
};