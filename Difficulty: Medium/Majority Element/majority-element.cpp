
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
          sort(arr.begin(), arr.end());
    int n = arr.size();
    int candidate = arr[n / 2];
    int count = 0;

    for (int num : arr) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        return candidate;
    } else {
        return -1;
    }
      
    }
};

