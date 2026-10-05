class Solution {
public:
    vector<int> pge(vector<int>& arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
            st.pop();
            if(st.empty())
                ans[i]=i+1;
            else
                ans[i]=i-st.top();
            st.push(i);
        }
        return ans;
    }
        vector<int> nge(vector<int>& arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
            if(st.empty())
                ans[i]=n-i;
            else
                ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        vector<int> left=pge(arr);
        vector<int> right=nge(arr);
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(long long)arr[i]*left[i]*right[i];
            ans%=mod;
        }
        return ans;
    }
};