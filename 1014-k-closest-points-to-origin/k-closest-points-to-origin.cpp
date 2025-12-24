class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> ans;
        priority_queue<pair<int ,pair<int,int>>> maxheap;
        for(int i=0;i<n;i++)
        {
            
            maxheap.push({arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1],{arr[i][0],arr[i][1]}});
            if(maxheap.size()>k)
            maxheap.pop();
        }
        while(maxheap.size()>0)
        {
            pair<int,int> p=maxheap.top().second;
            ans.push_back({p.first,p.second});
            maxheap.pop();
        }
        return ans;

        
    }
};