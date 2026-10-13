/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
   

  public:
  
   int height(Node* node) {
 if (node == NULL) {
            return 0; // no edges
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        // If it's a leaf, height is 0 (no edges below it)
        if (node->left == NULL && node->right == NULL) {
            return 0;
        }
        
        return 1 + max(left, right);
    }
};