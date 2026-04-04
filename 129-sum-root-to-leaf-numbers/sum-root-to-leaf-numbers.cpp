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
 void solve(TreeNode* root, int path, long long &ans) {
        if(root == NULL)
        return;

        path=path*10+root->val;
        if(root->left == NULL && root->right == NULL) {
           ans+=path;
           return;
        }

        solve(root->left, path, ans);
        solve(root->right, path, ans);
        //path-=root->val;
    }
    int sumNumbers(TreeNode* root) {
       long long ans=0;
        //int path=0;
        solve(root, 0, ans);
        return ans;
    }
};