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
    ListNode* insertionSortList(ListNode* head) {
          ListNode dummy(0);  // Dummy node to start the sorted list
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* prev = &dummy;
        // Find the right place to insert current node in sorted part
        while (prev->next != nullptr && prev->next->val < current->val) {
            prev = prev->next;
        }
        // Save next node to process after insertion
        ListNode* next = current->next;
        
        // Insert current node into sorted list
        current->next = prev->next;
        prev->next = current;

        // Move to the next node in the original list
        current = next;
    }
    return dummy.next;  // Head of the sorted list
    }
};