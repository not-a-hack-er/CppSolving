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
    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
        stack<int> s1,s2;
        while(num1!=NULL){
            s1.push(num1->val);
            num1=num1->next;
        }
        while(num2!=nullptr){
            s2.push(num2->val);
            num2=num2->next;
        }
        ListNode* head=NULL;
        int c=0;
        while(!s1.empty() || !s2.empty()){
            int sum=c;
            if(!s1.empty()){
                sum+=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum+=s2.top();
                s2.pop();
            }
            ListNode* newNode=new ListNode(sum%10);
            newNode->next=head;
            head=newNode;
            c=sum/10;
        }
        if(c){
            ListNode* newNode=new ListNode(c);
            newNode->next=head;
            head=newNode;
        }
        return head;
    }
};