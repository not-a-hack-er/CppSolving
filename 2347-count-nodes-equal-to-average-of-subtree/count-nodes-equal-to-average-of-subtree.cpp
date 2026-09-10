
class Solution {
public:
    int ans=0;
    pair<int,int> findAverage(TreeNode* node){
        if(node==nullptr)
            return {0,0};
        pair<int,int> left=findAverage(node->left);
        pair<int,int> right=findAverage(node->right);
        int sum=node->val + left.first + right.first;
        int c=1+left.second+right.second;
        int avg=sum/c;
        if(avg==node->val)
            ans++;
        return {sum,c};
    }
    int averageOfSubtree(TreeNode* root) {
        //use of count function
        findAverage(root);
        return ans;
    }
};