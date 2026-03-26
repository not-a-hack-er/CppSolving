class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);//int c=0;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            //c=0;
            while(!st.empty() && temperatures[i]>=temperatures[st.top()])
            {
            
            st.pop();
            }
            //ans[i]=c;
            if(!st.empty())
            ans[i]=st.top()-i;
           st.push(i);
        }
        return ans;
    }
};