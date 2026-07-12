class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        vector<int> ans;
        int n=arr.size();
        ans=arr;
        sort(ans.begin(),ans.end());
        int rank=1;
        for(int i=0;i<ans.size();i++){
            if(mp.find(ans[i])==mp.end()){
                mp[ans[i]]=rank;
                rank++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};