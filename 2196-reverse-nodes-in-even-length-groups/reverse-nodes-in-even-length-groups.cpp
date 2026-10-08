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
    ListNode* reverse(ListNode* head,int len){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=NULL && len>0){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;   
            len--; 
        }
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        int len=1;
        while(temp!=nullptr){
            ListNode* start=temp;
            int count=0;
            ListNode* last=nullptr;

            while(temp!=nullptr && count<len){
                last=temp;
                temp=temp->next;
                count++;
            }
            if(count%2==0){
                ListNode* newHead=reverse(start,count);
                if(prev!=nullptr){
                    prev->next=newHead;
                }
                start->next=temp;
                prev=start;
            }else{
                if(prev!=nullptr)
                    prev->next=start;
                prev=last;
            }
            len++;
        }
        return head;
    }
};