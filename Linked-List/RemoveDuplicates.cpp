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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *a = head;
        ListNode *b;
        
        if(!head)
            return NULL;
        
        while(a->next != NULL) {
            if(a->next->val == a->val) {
                b = a->next->next;
                a->next = b;
            }
            else {
                a = a->next;
            }
        }
        return head;
    }
};
