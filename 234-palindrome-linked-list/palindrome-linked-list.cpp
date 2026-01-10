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
ListNode* curr;
bool isPalindrome(ListNode* head) {
       curr = head;
        return check(head);
    }
bool check(ListNode* node) {
        if (node == nullptr) return true;
        bool isRestPalindrome = check(node->next);
        if (!isRestPalindrome || curr->val != node->val) {
            return false;
        }
        curr = curr->next;
        return true;
    }
    
};