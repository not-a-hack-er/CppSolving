class Solution {
public:
int binarySearch(int target, int left, int right) {
        if (left > right) {
            return right;
        }
        int mid = left + (right - left) / 2;
        long long square = (long long)mid * mid;
        if (square == target) {
            return mid;
        } else if (square < target) {
           
            return binarySearch(target, mid + 1, right);
        } else {
            return binarySearch(target, left, mid - 1);
        }
    }
    int mySqrt(int x) {
        if (x < 2) return x;
        return binarySearch(x, 1, x / 2);
    }
};