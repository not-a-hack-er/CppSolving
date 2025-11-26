class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Make a vector of pairs: {number, frequency}
        vector<pair<int, int>> freqList;
        for (auto it : freq) {
            freqList.push_back({it.first, it.second});
        }
        
        // Sort the vector by frequency, highest first
        sort(freqList.begin(), freqList.end(),
             [](pair<int,int> a, pair<int,int> b) {
                 return a.second > b.second;
             });
        
        // Get the first k elements
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(freqList[i].first);
        }
        return ans;



    }
};