
// User function Template for C++

class Solution {
  public:
    Node *moveToFront(Node *head) {
         
        Node* temp = head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        Node*curr=temp->next;
        temp->next=NULL;
        curr->next=head;
        return curr;
    }
    
};

