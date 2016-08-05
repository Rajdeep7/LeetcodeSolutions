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
    void reorderList(ListNode* head) {
        if(!head) {
            return;
        }
        if(head->next==NULL) {
            return;
        }
        
        ListNode *sp = head;
        ListNode *fp = head;

        int i = 0;
        
        while(fp->next && fp->next->next) {
            sp = sp->next;
            fp = fp->next->next;
        }
        
        fp = sp->next;

        while(fp->next != NULL) {
            ListNode* tmp = sp->next;
            sp->next = fp->next;
            fp->next = fp->next->next;
            sp->next->next = tmp;
        }
        
        fp = head;        

        while(sp!=fp && sp->next) {
            ListNode *tmp = fp->next;
            fp->next = sp->next;
            sp->next = sp->next->next;
            fp->next->next = tmp;
            fp = fp->next->next;
        }
        return;
    }
    
};
