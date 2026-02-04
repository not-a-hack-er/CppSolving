class Solution {
public:
    int minTimeToType(string word) {
    int t= 0;
        char curr = 'a';

        for (char c : word) {
            int diff = abs(c - curr);
            t += min(diff, 26 - diff); 
            t += 1;         
            curr = c;
        }
        return t;
    }
};