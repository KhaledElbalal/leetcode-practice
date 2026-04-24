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
        if(!head || !head->next)
            return false;
        ListNode* turtle = head;
        ListNode* hare = head;
        while(hare && hare->next) {
            turtle = turtle->next;
            hare = hare->next->next;

            if(hare == turtle) {
                return true;
            }
        }
        return false;
    }
};
