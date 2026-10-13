
// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
 set<int> s;
    for (int x : a) s.insert(x);
    for (int x : b) s.insert(x);
    return vector<int>(s.begin(), s.end());
    }
};

