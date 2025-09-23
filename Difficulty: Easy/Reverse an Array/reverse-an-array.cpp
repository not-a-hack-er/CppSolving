
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
  
    int left = 0, right = arr.size() - 1;
  
    // Iterate till left is less than right
    while(left < right) {
      
        // Swap the elements at left and right position
        swap(arr[left], arr[right]);
      
        // Increment the left pointer
        left++;
      
        // Decrement the right pointer
        right--;
    }
   
    }
          
};

