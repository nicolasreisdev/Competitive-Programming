/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> aux;
        ListNode* curr = head;
        while(curr){
            if(aux.find(curr) != aux.end()) return true;
            aux.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};