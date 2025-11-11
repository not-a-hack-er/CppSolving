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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode dummy(0);
    dummy.next = head;

    ListNode* prev = &dummy;
    ListNode* curr = head;

    while (curr != nullptr) {
        // Check for duplicates
        while (curr->next != nullptr && curr->val == curr->next->val) {
            curr = curr->next;
        }
        // If prev's next is still curr, no duplicates
        if (prev->next == curr) {
            prev = prev->next;
        } else {
            // Skip all duplicates
            prev->next = curr->next;
        }
        curr = curr->next;
    }
    return dummy.next;
        
    }
};