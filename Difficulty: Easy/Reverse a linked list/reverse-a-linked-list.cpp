
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while(curr!=NULL)
        {
            Node* forward = curr->next;
            curr->next =prev;
            prev= curr;
            curr=forward;
            }
            return prev;
    }
};


