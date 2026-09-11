class Solution {
public:
    struct State {
        int row; int col; int energy; int mask;
    };
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int pos[20][20];
        int cnt = 0;
        int sr = 0, sc = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pos[i][j] = -1;
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    pos[i][j] = cnt;
                    cnt++;
                }
            }
        }
        if (cnt == 0)
            return 0;
        int all = (1 << cnt) - 1;
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(energy + 1,
                                           vector<bool>(1 << cnt, false))));
                                           queue<State> q;
                                           q.push({sr,sc,energy,0});
                                           visited[sr][sc][energy][0]=true;
                                           int ans=0;
                                           int dr[4]={0,0,1,-1};
                                           int dc[4]={1,-1,0,0};
                                           while(!q.empty()){
                                            int size=q.size();
                                            while(size--){
                                                State cur=q.front();
                                                q.pop();
                                                if(cur.mask==all)
                                                return ans;
                                                if(cur.energy==0)
                                                continue;
                                                for(int d=0;d<4;d++){
                                                    int nr=cur.row+dr[d];
                                                    int nc=cur.col+dc[d];
                                                    if(nr<0||nr>=m||nc<0||nc>=n)
                                                    continue;
                                                    if(classroom[nr][nc]=='X')
                                                    continue;
                                                    int newEne=cur.energy-1;
                                                    int newMask=cur.mask;
                                                    if(classroom[nr][nc]=='R')
                                                    newEne=energy;
                                                    if(classroom[nr][nc]=='L')
                                                    newMask|=(1<<pos[nr][nc]);
                                                    if(!visited[nr][nc][newEne][newMask]){
                                                        visited[nr][nc][newEne][newMask]=true;
                                                        q.push({nr,nc,newEne,newMask});
                                                    }
                                                }
                                            }
                                           
    
                                           ans++;
}
return -1;
    }
    //return -1
};