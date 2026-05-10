/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* curr = head;
        Node* newList = new Node(curr->val);
        Node* currNewList = newList;
        map<Node*, Node*> mp;
        mp[head] = newList;
        while(curr->next) {
            curr = curr->next;
            currNewList->next = new Node(curr->val);
            currNewList = currNewList->next;
            mp[curr] = currNewList;
        }
        curr = head;
        currNewList = newList;
        while(curr) {
            if(curr->random) currNewList->random = mp[curr->random];
            curr = curr->next;
            currNewList = currNewList->next;
        }
        return newList;
    }
};
