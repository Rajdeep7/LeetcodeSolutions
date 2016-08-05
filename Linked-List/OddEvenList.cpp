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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *connect = q;
        
        while(p!=NULL && q!=NULL && q->next!=NULL) {
            p->next = q->next;
            p = p->next;
            
            q->next = p->next;
            q = q->next;
        }
        p->next = connect;
        
        return head;
    }
};
