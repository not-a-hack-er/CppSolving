class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            int element=nums2[i];
            while(!st.empty() && st.top()<element)
                st.pop();
            if(st.empty())
                nge[i]=-1;
            else
                nge[i]=st.top();
            st.push(element);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nge[j]);
                }
            }
        }
        return ans;
    }
};