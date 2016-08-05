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
    ListNode* partition(ListNode* head, int x) {
        ListNode *cur = new ListNode(0);
        cur->next = head;
        head = cur;
        ListNode *last = head;
        int size = 0;
        
        if(head == NULL)
            return NULL;
        
        if(head->next == NULL)
            return head->next;
        
        while(last->next != NULL) {
            last = last->next;
            size++;
        }
        while(size > 0) {
            if(cur->next->val < x) {
                cur = cur->next;
                size--;
            }
            else {
                last->next = new ListNode(cur->next->val);
                last = last->next;
                cur->next = cur->next->next;
                size--;
            }
            
        }
        return head->next;
    }
};
