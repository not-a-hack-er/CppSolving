class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for (int i = 0; i < size; i++) {
            if ((i == 0 || flowerbed[i - 1] == 0)
                && flowerbed[i] == 0 &&
                    (i == size - 1 || flowerbed[i + 1] == 0)) {
                    n--;
                    flowerbed[i] = 1;
                }
        }
        return n <= 0;
    }
};