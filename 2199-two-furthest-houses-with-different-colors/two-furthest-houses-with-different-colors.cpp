class Solution {
public:
    int maxDistance(vector<int>& colors) {
      int n = colors.size();
        int maxd = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (colors[i] != colors[0]) {
                maxd = max(maxd, i);
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[n - 1]) {
                maxd = max(maxd, (n - 1) - i);
                break;
            }
        }
        return maxd;  
    }
};