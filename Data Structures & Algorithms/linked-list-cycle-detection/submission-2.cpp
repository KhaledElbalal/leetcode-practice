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
    bool hasCycle(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return false;
        ListNode* turtle = head->next, *hare = head->next->next;
        while(hare && turtle) {
            if(hare == turtle) {
                return true;
            }
            turtle = turtle->next;
            if(hare->next)
                hare = hare->next->next;
            else
                return false;
        }
        return false;
    }
};
