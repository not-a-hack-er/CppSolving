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
 class Compare {
public:
    // Comparator to order ListNode pointers based on node values
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a min-heap (priority queue) with custom comparator
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Push the head of each non-empty list into the heap
        for (auto list : lists) {
            if (list != NULL)
                pq.push(list);
        }

        // Create a dummy node to build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // While the heap is not empty
        while (!pq.empty()) {
            // Extract the node with the smallest value
            ListNode* smallest = pq.top();
            pq.pop();

            // Add it to the result list
            tail->next = smallest;
            tail = tail->next;

            // If there's a next node, push it into the heap
            if (smallest->next != NULL)
                pq.push(smallest->next);
        }

        // Return the head of the merged list
        return dummy->next;
        
    }
};