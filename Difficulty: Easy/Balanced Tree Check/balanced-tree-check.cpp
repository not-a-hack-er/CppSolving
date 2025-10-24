/*

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
  public:
   pair<bool, int> checkBalanced(Node* node) {
        if (!node) return {true, 0};  // Empty subtree is balanced and height 0
        
        auto left = checkBalanced(node->left);
        if (!left.first) return {false, 0};  // Left subtree not balanced
        
        auto right = checkBalanced(node->right);
        if (!right.first) return {false, 0};  // Right subtree not balanced
        
        bool balanced = abs(left.second - right.second) <= 1;
        int height = 1 + max(left.second, right.second);
        
        return {balanced, height};
   }
    bool isBalanced(Node* root) {
         return checkBalanced(root).first;
    }
};