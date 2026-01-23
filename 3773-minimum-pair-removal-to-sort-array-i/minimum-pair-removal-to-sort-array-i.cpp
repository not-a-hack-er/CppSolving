class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
         vector<int> list(nums.begin(), nums.end());

        if (isSorted(list)) return 0;

        int cnt = 0;
        while (!isSorted(list)) {
            int sum = INT_MAX;
            int idx = -1;

            for (int i = 0; i < (int)list.size() - 1; i++) {
                int currSum = list[i] + list[i + 1];
                if (currSum < sum) {
                    sum = currSum;
                    idx = i;
                }
            }

            int merged = list[idx] + list[idx + 1];
            list.erase(list.begin() + idx + 1);
            list[idx] = merged;
            cnt++;
        }
        return cnt;
    }

    bool isSorted(const vector<int>& list) {
        for (int i = 0; i < (int)list.size() - 1; i++) {
            if (list[i] > list[i + 1]) return false;
        }
        return true;
    }
};