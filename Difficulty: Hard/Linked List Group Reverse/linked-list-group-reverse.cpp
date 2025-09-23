
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if(head==NULL)
        return NULL;
        Node* next=NULL;
        Node* curr=head;
        Node* prev=NULL;
        int count=0;
        while(curr!=NULL && count<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        
        if(next!=NULL)
        {
            head->next=reverseKGroup(next, k);
        }
        return prev;
    }
};


