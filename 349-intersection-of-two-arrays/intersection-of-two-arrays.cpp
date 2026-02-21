class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         unordered_set<int> s(nums2.begin(), nums2.end());
        unordered_set<int> result;

        for (int x : nums1) {
            if (s.find(x) != s.end()) {
                result.insert(x);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};