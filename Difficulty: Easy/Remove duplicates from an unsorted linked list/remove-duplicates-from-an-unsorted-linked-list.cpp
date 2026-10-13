
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
       if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        map<int,bool> visited;
        
        Node *prev = NULL;
        Node *current = head;
        Node *forward = NULL;
        while(current != NULL)
        {
            if(visited[current->data] == 1)
            {
                forward = current->next;
                prev->next = forward;
                Node *dltnode = current ;
                delete dltnode ;
                current = forward;
                
            }
            else 
            {
                visited[current->data] = 1;
                prev = current ;
                current = current->next;
            }
        }
        
        return head;
    }
};


