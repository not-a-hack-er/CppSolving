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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* large=new ListNode(0);
        ListNode* smallp=small;
        ListNode* largep=large;
        while(head!=nullptr){
            ListNode* next = head->next;
        if(head->val<x){
            smallp->next=head;
            smallp=smallp->next;
        }else{
            largep->next=head;
            largep=largep->next;
        }
        head->next = nullptr;
        head = next;
        }
        smallp->next=large->next;
        largep->next=NULL;
        return small->next;
    }
};