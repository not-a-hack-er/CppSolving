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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool evenlevel=true;
        while(!q.empty()){
            int n=q.size();
            int prev;
            if(evenlevel)
                prev=INT_MIN;
            else
                prev=INT_MAX;
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                if(evenlevel && (curr->val%2==0 || curr->val <=prev))
                    return false;
                if(!evenlevel && (curr->val%2!=0 || curr->val>=prev))
                    return false;

                prev=curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            evenlevel=!evenlevel;
        }
        return true;
    }
};