class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prevRow={(double)poured};
        for(int r=1;r<=query_row;r++){
            vector<double> curRow(r+1,0);
            for(int i=0;i<r;i++){
                double ex=prevRow[i]-1.0;
                if(ex>0){
                    curRow[i]+=ex/2.0;
                    curRow[i+1]+=ex/2.0;
                }
            }
            prevRow=curRow;
        }
        return min(1.0,prevRow[query_glass]);
    }
};