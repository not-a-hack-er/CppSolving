class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     

        vector<int> merged;
        int n = nums1.size(), m = nums2.size();
        
        // Merge the two arrays
        merged.insert(merged.end(), nums1.begin(), nums1.end());
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        sort(merged.begin(), merged.end());
        
        int total = merged.size();
        // Odd length: take the middle element
        if (total % 2 == 1) {
            return merged[total / 2];
        }
        // Even length: average the two middle elements
        else {
            return (merged[total/2 - 1] + merged[total/2]) / 2.0;
        }
    }
};
