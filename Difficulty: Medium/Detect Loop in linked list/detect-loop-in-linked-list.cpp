
// User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        Node* slow =head;
        Node* fast=head;
      if(head==NULL)
      {
          return NULL;
      }
      while(slow!=NULL && fast!=NULL)
      {
          fast=fast->next;
          if(fast!=NULL)
          {
              fast=fast->next;
          }
          slow=slow->next;
          if(slow==fast)
          {
              return slow;
          }
      }
          
     return NULL; 
    }
};


