class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> first(26,n);
        vector<int> last(26,-1);
        for(int i=0;i<n;i++){
            int x=s[i]-'a';
            first[x]=min(first[x],i);
            last[x]=i;
        }
        vector<pair<int,int>> v;
        for(int i=0;i<26;i++){
            if(last[i]==-1)
            continue;
            int l=first[i];
            int r=last[i];
            bool flag=true;
            for(int j=l;j<=r;j++){
                int x=s[j]-'a';
                if(first[x]<l){
                    flag=false;
                    break;
                }
                r=max(r,last[x]);
            }
            if(flag)
            v.push_back({l,r});
        }
        sort(v.begin(), v.end(), [](auto a, auto b) {
    return a.second < b.second;
});
        vector<string> ans;
        int end=-1;
        for(auto x:v){
            if(x.first>end){
                ans.push_back(s.substr(x.first,x.second-x.first+1));
                end=x.second;
            }
        }
        return ans;
    }
};