class Solution {
  public:
    // Function to delete middle element of a stack.
    void solve(stack<int>&s,int count,int size)
    {
        //base condn
        if(count==size/2)
        {
            s.pop();
            return;
        }
    
            int ch=s.top();
            s.pop();
            solve(s,count+1,size);
            s.push(ch);
        
  
    }
    
    
    
    
    void deleteMid(stack<int>& s)
    {
     int count=0;
     int size=s.size();
      solve(s,count,size);

      }
    
};