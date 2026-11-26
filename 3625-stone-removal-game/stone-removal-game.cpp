class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool alice = true;

        while (stones > 0 && n >= stones) {
            n -= stones;
            stones--;

            alice = !alice;
        }

        return !alice;
    }
};