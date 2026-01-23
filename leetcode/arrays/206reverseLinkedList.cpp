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
    ListNode* reverse(ListNode* head, ListNode* prev){
        if(!head)return prev;
        ListNode* newHead = reverse(head->next, head);
        head->next = prev;
        return newHead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr);
    }
};