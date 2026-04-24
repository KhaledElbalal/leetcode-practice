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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* headRef = head;
        nodes.push_back(head);
        while(head->next) {
            head = head->next;
            nodes.push_back(head);
        }
        int n = nodes.size();
        cout << n << endl;
        for(int i = 1; i <= n/2; i++) {
            headRef->next = nodes[n-i];
            headRef = headRef->next;
            if(i != n - i) {
                headRef->next = nodes[i];
                headRef = headRef->next;
            }
        }
        headRef->next = nullptr;
    }
};