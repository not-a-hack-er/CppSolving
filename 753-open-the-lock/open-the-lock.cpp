class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<bool> dead(10000,false);
        vector<bool> vis(10000,false);
        for(string s:deadends){
            dead[stoi(s)]=true;
        }
        if(dead[0])
            return -1;
        queue<string> q;
        q.push("0000");
        vis[0]=true;
        int steps=0; 
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string curr=q.front();
                q.pop();
                if(curr==target)
                    return steps;
                for(int i=0;i<4;i++){
                    string next=curr;
                    next[i]=(curr[i]=='9')?'0':curr[i]+1;
                    int num=stoi(next);

                    if(!dead[num] && !vis[num]){
                        q.push(next);
                        vis[num]=true;
                    }
                    next=curr;
                    next[i]=(curr[i]=='0')?'9':curr[i]-1;
                    num=stoi(next);
                    if(!dead[num] && !vis[num]){
                        q.push(next);
                        vis[num]=true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};