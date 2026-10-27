class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            int j = i;

            while (j + m <= n) {
                int k;
                for (k = 0; k < m; k++) {
                    if (sequence[j + k] != word[k])
                        break;
                }

                if (k == m) {
                    temp++;
                    j += m;
                } else {
                    break;
                }
            }

            count = max(count, temp);
        }

        return count;
    }
};