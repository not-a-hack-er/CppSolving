class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
unordered_map<int, int> ab;
for(int i = 0; i < nums.size(); i++) {
    ab[nums[i]]++;       // Count frequencies
}
priority_queue<pair<int,int>> heap;
for(auto& p : ab) {
    heap.push({p.second, p.first});  // Push {frequency, value}
}
vector<int> ans;
for(int i = 0; i < k && !heap.empty(); i++) {
    ans.push_back(heap.top().second);  // Get most frequent value
    heap.pop();
}
return ans;



    }
};