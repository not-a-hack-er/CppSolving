class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for (int x : nums2) {
            if (s.find(x) != s.end()) {
                result.insert(x);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};