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
    int ans = 0;

    int dfs(TreeNode* root) {
        if(root == NULL) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int l = 0, r = 0;

        if(root->left && root->val == root->left->val)
            l = left + 1;

        if(root->right && root->val == root->right->val)
            r = right + 1;

        ans = max(ans, l + r);

        return max(l, r);
    }
    int longestUnivaluePath(TreeNode* root) {
    ans = 0;
    dfs(root);
    return ans;
}
};