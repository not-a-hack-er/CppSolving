class Solution {
public:
         int n;
        vector<vector<int>> result;
        void solve(unordered_map<int,int> &mp,vector<int> &temp)
        {
            for(auto& [num,count]:mp)
            {
                if(temp.size()==n)
                {
                    result.push_back(temp);
                    return;
                }
                if(count==0)
                continue;
                temp.push_back(num);
                mp[num]--;
                solve(mp,temp);
                temp.pop_back();
                mp[num]++;
            }
        }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       n=nums.size();
       unordered_map<int,int> mp;
       for(int i:nums)
       {
        mp[i]++;
       }
       vector<int> temp;
       solve(mp,temp);
       return result;

    }
};