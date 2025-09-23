
// User function template for C++

class Solution {
  public:
  
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
       int r=arr.size()-1;
        priority_queue<int> pq;
        
        for(int i=0;i<k;i++)
        {
            pq.push(arr[i]);
        }
        
        for(int i=k;i<=r;i++)
        {
            if(arr[i]<pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans=pq.top();
        return ans;
    }
};

