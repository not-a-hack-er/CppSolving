class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int n=seq.size();
        int d=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='(')
                d++;
            ans.push_back(d%2);
            if(seq[i]==')')
                d--;
        }
        return ans;
    }
};