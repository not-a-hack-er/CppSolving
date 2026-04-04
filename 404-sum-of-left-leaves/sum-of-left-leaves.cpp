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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
        return 0;
        //int s=0;
        return sum(root);
    }
    int sum(TreeNode* node)
    {
        if(node==NULL)
        return 0;
        int s=0;
        if(node->left)
        {
        if(node->left->right==NULL && node->left->left==NULL)
        s+=node->left->val;
        else
        s+= sum(node->left);
        }
        s+=sum(node->right);
        return s;
    }
};