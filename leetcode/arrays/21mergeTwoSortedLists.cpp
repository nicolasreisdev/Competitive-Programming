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
    void merge(ListNode* curr1, ListNode* curr2, ListNode* prev){
        if(!curr1 and !curr2) return;
        if(!curr1){
            prev->next = curr2;
            merge(curr1, curr2->next, curr2);
            return;
        }
        if(!curr2){
            prev->next = curr1;
            merge(curr1->next, curr2, curr1);
            return;
        }
        if(curr1->val < curr2->val){
            prev->next = curr1;
            merge(curr1->next, curr2, curr1);
        }
        else if(curr1-> val > curr2->val){
            prev->next = curr2;
            merge(curr1, curr2->next, curr2);
        }
        else{
            prev->next = curr1;
            merge(curr1->next, curr2, curr1);
        }
        return;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans;
        if(!list1 and !list2) return nullptr;
        if(!list1)return list2;
        if(!list2) return list1;
        if(list1->val <= list2->val){
            merge(list1->next, list2, list1);
            ans = list1;
        }
        else{
            merge(list1, list2->next, list2);
            ans = list2;
        }
        return ans;
    }
};