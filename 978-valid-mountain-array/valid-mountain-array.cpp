class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        int n = arr.size();
        if (n < 3) return false; // Must have at least 3 elements

        int i = 0;
        // Strictly increasing
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // Peak can't be at the ends
        if (i == 0 || i == n - 1) return false; 

        // Strictly decreasing
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        // If reached end, it's valid
        if(i== n - 1)
        return true;
        else
        return false;

    }
};