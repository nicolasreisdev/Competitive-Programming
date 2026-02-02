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
private:
    ListNode* reverseLinkedList(ListNode* root, ListNode* prev){
        if(!root) return prev;
        ListNode* newRoot = reverseLinkedList(root->next, root);
        root->next = prev;
        return newRoot;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* rootReversed = reverseLinkedList(head, nullptr);
        ListNode* currNode = rootReversed;
        ListNode* prev = nullptr;
        while(n != 1 and currNode->next){
            prev = currNode;
            currNode = currNode->next;
            n--;
        }
        if(!prev) return reverseLinkedList(rootReversed->next, nullptr);
        prev->next = currNode->next;
        return reverseLinkedList(rootReversed, nullptr);
    }
};