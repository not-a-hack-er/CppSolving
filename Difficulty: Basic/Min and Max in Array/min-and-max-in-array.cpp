
// User function Template for C++
class Solution {
  public:
   vector<int> getMinMax(vector<int> arr) {
        // code here
        int l= arr.size();
        int max=INT_MIN; int min=INT_MAX;
        for(int i=0;i<l;i++)
        {
            if(max<arr[i])
            {
            max=arr[i];
            }
            if(min>arr[i])
            {
            min=arr[i];
            }
        }
  return {min,max};
    }
};

