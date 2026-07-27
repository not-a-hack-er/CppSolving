class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            int n=i;
            bool ok=true;
            while(n>0){
                int d=n%10;
                if(d==0 || i%d!=0){
                    ok=false;
                    break;
                }
                n/=10;
            }
            if(ok)
            ans.push_back(i);
        }
        return ans;
    }
};