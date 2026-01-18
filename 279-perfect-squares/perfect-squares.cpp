#include <iostream>
#include <cmath>

class Solution {
public:
    bool isSquare(int n) {
        int sq = sqrt(n);
        return (sq * sq == n);
    }

    int numSquares(int n) {
        if (isSquare(n)) return 1;
        int temp = n;
        while (temp % 4 == 0) {
            temp /= 4;
        }
        if (temp % 8 == 7) return 4;
        for (int i = 1; i * i <= n; i++) {
            if (isSquare(n - i * i)) {
                return 2;
            }
        }
        return 3;
    }
};