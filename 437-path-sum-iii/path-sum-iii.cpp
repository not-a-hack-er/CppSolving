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
    int total = 0;

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        unordered_map<long long, int> mp;
        mp[0] = 1;   
        
        dfs(root, 0, targetSum, mp);
        return total;
    }

private:
    void dfs(TreeNode* node, long long currSum, int target,
             unordered_map<long long, int>& mp) {
        
        if (!node) return;

        currSum += node->val;

        if (mp.count(currSum - target))
            total += mp[currSum - target];

        mp[currSum]++;

        dfs(node->left, currSum, target, mp);
        dfs(node->right, currSum, target, mp);

        
        mp[currSum]--;
    }
};