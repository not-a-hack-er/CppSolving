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
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL)
            return NULL;

        ListNode* oddDummy = new ListNode(-1);
        ListNode* evenDummy = new ListNode(-1);

        ListNode* odd = oddDummy;
        ListNode* even = evenDummy;

        ListNode* temp = head;

        int pos = 1;

        while(temp != NULL)
        {
            ListNode* nextNode = temp->next;
            temp->next = NULL;

            if(pos % 2 == 1)
            {
                odd->next = temp;
                odd = odd->next;
            }
            else
            {
                even->next = temp;
                even = even->next;
            }

            temp = nextNode;
            pos++;
        }

        odd->next = evenDummy->next;

        return oddDummy->next;
    }
};