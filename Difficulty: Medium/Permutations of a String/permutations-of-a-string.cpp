
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void backtrack(string &s, vector<string> &result, int index) {
        if (index == s.size()) {
            result.push_back(s);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            bool should_swap = true;
            // Check if the current character has been used before in this position
            for (int j = index; j < i; ++j) {
                if (s[j] == s[i]) {
                    should_swap = false;
                    break;
                }
            }
            if (should_swap) {
                swap(s[index], s[i]);
                backtrack(s, result, index + 1);
                swap(s[index], s[i]); // Backtrack
            }
        }
    }

    vector<string> findPermutation(string s) {
        vector<string> result;
        sort(s.begin(), s.end()); // Sort to handle duplicates
        backtrack(s, result, 0);
        return result;
    }
};


