/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;    
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head=reverse(head);
        ListNode* temp=head;
        int maxi=temp->val;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->next->val < maxi){
                temp->next=temp->next->next;
            }else{
                temp=temp->next;
                maxi=temp->val;
            }
        }
        head=reverse(head);
        return head;
    }
};