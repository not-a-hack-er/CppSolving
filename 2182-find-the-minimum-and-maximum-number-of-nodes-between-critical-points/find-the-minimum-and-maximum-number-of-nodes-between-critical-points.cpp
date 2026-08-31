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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        //vector<int> temp;
        ListNode* temp=head;
        int c=1;
        while(temp->next->next!=NULL){
            if((temp->next->val>temp->val && temp->next->next->val<temp->next->val) || (temp->next->val<temp->val && temp->next->next->val>temp->next->val))
                ans.push_back(c+1);
            c++;
            temp=temp->next;
        }
        if(ans.size()<2)
            return {-1,-1};
        int mn=INT_MAX;
        for(int i=1;i<ans.size();i++)
            mn=min(mn,ans[i]-ans[i-1]);
        int mx=ans.back()-ans.front();
        return {mn,mx};
    }
};