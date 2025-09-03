
// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
    // Function to sort an array using Heap Sort.
  void heapify(vector<int>& arr, int n, int i) {  // Pass by reference
    int largest = i;
    int left = 2 * i + 1;  // 0-based indexing
    int right = 2 * i + 2; // 0-based indexing
    
    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int size = arr.size();
    
    // Build max heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    
    // Extract elements from heap one by one
    while (size > 1) {
        swap(arr[0], arr[size - 1]); // Move current root to end
        size--;
        heapify(arr, size, 0); // call max heapify on the reduced heap
    }
}
};


