class Solution {
public:
    bool makesquare(vector<int>& m) {
        int n=m.size();
        int s=0;
        for(int i=0;i<n;i++)
            s+=m[i];
        if(s%4!=0)
            return false;
        int l=s/4;
        vector<int> sides(4,0);
        sort(m.rbegin(),m.rend());
        return backtrack(0,m,sides,l);
    }
    bool backtrack(int i,vector<int> &m,vector<int>& sides,int l){
        if(i==m.size())
            return true;
        for(int j=0;j<4;j++){
            if(sides[j]+m[i]<=l){
                sides[j]+=m[i];

                if(backtrack(i+1,m,sides,l))
                    return true;
                sides[j]-=m[i];
            }
        }
        return false;
    }
};