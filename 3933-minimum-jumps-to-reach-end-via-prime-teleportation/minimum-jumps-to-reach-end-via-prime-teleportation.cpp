class Solution {
public:

    bool prime(int n) {
        if(n < 2)
            return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0)
                return false;
        }
        return true;
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            for(int d = 1; d * d <= nums[i]; d++) {
                if(nums[i] % d == 0) {
                    mp[d].push_back(i);
                    if(d != nums[i] / d)
                        mp[nums[i] / d].push_back(i);
                }
            }
        }
        queue<int> q;
        vector<int> vis(n, 0);
        unordered_set<int> used;
        q.push(0);
        vis[0] = 1;
        int step = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int i = q.front();
                q.pop();
                if(i == n - 1)
                    return step;
                if(i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }
                if(i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }
                if(prime(nums[i]) &&
                   !used.count(nums[i])) {
                    used.insert(nums[i]);
                    for(int j : mp[nums[i]]) {
                        if(!vis[j]) {
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};