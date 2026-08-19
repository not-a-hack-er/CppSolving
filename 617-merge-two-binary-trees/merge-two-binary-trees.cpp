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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
    }
    TreeNode* solve(TreeNode* t1, TreeNode* t2){
        if(t1==NULL && t2==NULL)
            return NULL;
        if(t1==NULL && t2!=NULL)
            return t2;
        if(t2==NULL && t1!=NULL)
            return t1;
        TreeNode* sum = new TreeNode(t1->val+t2->val);
        sum->left=solve(t1->left,t2->left);
        sum->right=solve(t1->right,t2->right);
        return sum;
    }
    //return sum;
};