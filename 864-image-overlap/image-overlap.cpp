class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        for(int d=-(n-1);d<=n;d++){
            for(int r=-(n-1);r<=n;r++){
                int c=0;
                for(int row=0;row<n;row++){
                    for(int col=0;col<n;col++){
                        if(img1[row][col]==1){
                            int newR=row+d;
                            int newC=col+r;
                            if(newR>=0 && newR<n && newC>=0 && newC<n && img2[newR][newC]==1){
                                c++;
                            }
                        }
                    }
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};