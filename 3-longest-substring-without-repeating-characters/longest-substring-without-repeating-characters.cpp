class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      
    set<char> chars;        // To store current window characters
    int left = 0, right = 0;
    int maxLength = 0;

    while (right < s.size()) {
        if (chars.find(s[right]) == chars.end()) { // If char not in set
            chars.insert(s[right]);
            right++;
            maxLength = max(maxLength, right - left);
        } else {
            chars.erase(s[left]);
            left++;
        }
    }
    return maxLength;
        
    }
};