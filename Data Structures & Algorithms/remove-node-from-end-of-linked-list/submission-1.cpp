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
    ListNode* removeNthNode(ListNode* head, int n) {
        if(n == 0) {
            if(head->next) {
                return head->next;
            }
            return nullptr;
        }
        else if(n == 1) {
            if(head->next) head->next = head->next->next;
        }
        else {
            removeNthNode(head->next, n - 1);
        };
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* it = head;
        while(it != nullptr) {
            it = it->next;
            sz++;
        }
        cout << sz << ' ' << head->val << endl;
        head = removeNthNode(head, sz - n);
        return head;
    }
};
