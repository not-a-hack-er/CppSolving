class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numWithIndex;
    for (int i = 0; i < nums.size(); i++)
        numWithIndex.push_back({nums[i], i});

    sort(numWithIndex.begin(), numWithIndex.end());

    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = numWithIndex[left].first + numWithIndex[right].first;
        if (sum == target)
            return {numWithIndex[left].second, numWithIndex[right].second};
        else if (sum < target)
            left++;
        else
            right--;
    }
    return ;
    }
};
