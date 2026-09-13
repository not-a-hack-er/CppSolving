class Solution {
public:
    struct Node{
        long long score;
        vector<int> ids;
    };
    bool better(Node a,Node b){
        if(a.score!=b.score)
            return a.score>b.score;
        return a.ids<b.ids;
    }
    vector<int> maximumWeight(vector<vector<int>>& ac) {
        int n=ac.size();
        for(int i=0;i<n;i++)
            ac[i].push_back(i);
        sort(ac.begin(),ac.end());
        vector<int> s(n);
        for(int i=0;i<n;i++)
            s[i]=ac[i][0];
        vector<int> next(n);
        for(int i=0;i<n;i++){
            next[i]=upper_bound(s.begin(),s.end(),ac[i][1])-s.begin();
        }
        vector<vector<Node>> dp(n+1,vector<Node>(5));
        for(int i=n-1;i>=0;i--){
            for(int k=1;k<=4;k++){
                Node nt=dp[i+1][k];
                Node t=dp[next[i]][k-1];
                t.score+=ac[i][2];
                t.ids.push_back(ac[i][3]);
                sort(t.ids.begin(),t.ids.end());
                if(better(t,nt))
                    dp[i][k]=t;
                else
                    dp[i][k]=nt;
            }
        }
        return dp[0][4].ids;
    }
};