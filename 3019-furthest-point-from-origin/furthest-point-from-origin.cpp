class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, blank = 0;

        for(char c : moves) {
            if(c == 'L') L++;
            else if(c == 'R') R++;
            else blank++;
        }

        return abs(L - R) + blank;
    }
};