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
ListNode *reverseList(ListNode *head) {

    ListNode *curr = head, *prev = nullptr, *next;

    // Traverse all the nodes of Linked List
    while (curr != nullptr) {

        // Store next
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

    return prev;
}
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
    ListNode* slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* second = reverseList(slow->next);
    ListNode* first = head;

    while (second) {
        if (first->val != second->val) return false;
        first = first->next;
        second = second->next;
    }
    return true;
        
    }
};