/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int solve(TreeNode* root,map<int,int>& mp,int& freq)
{
    if(root == NULL)
    return 0;
    int sum=0;
    int l=solve(root->left,mp,freq);
    int r=solve(root->right,mp,freq);

    sum=root->val+l+r;
    mp[sum]++;

    freq=max(freq,mp[sum]);

    return sum;

}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        map<int,int> mp;
        int freq=0;

        solve(root,mp,freq);

        for(auto it:mp)
        {
            if(it.second==freq)
            ans.push_back(it.first);
        }
        return ans;
    }
};