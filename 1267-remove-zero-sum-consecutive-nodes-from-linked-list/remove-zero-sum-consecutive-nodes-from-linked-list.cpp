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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp1 = head;
        while (temp1 != nullptr) {
            ListNode* temp2 = temp1;
            int sum = 0;
            bool removed = false;
            while (temp2 != nullptr) {
                sum += temp2->val;
                if (sum == 0) {
                    if (temp1 == head) {
                        head = temp2->next;
                    } else {
                        ListNode* prev = head;
                        while (prev->next != temp1)
                            prev = prev->next;
                        prev->next = temp2->next;
                    }
                    removed = true;
                    break;
                }
                temp2 = temp2->next;
            }
            if (removed)
                temp1 = head;
            else
                temp1 = temp1->next;
        }
        return head;
    }
};