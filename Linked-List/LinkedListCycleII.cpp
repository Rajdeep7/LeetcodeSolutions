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
    ListNode *detectCycle(ListNode *head) {
        ListNode *sp = head;
        ListNode *fp = head;
        int flag = 0;
       
       if(head == NULL)
        return NULL;
       
        while(1) {
            if(sp->next != NULL) 
                sp = sp->next;
            else
                return NULL;
                
            if(fp->next!=NULL && fp->next->next!=NULL)     
                fp = fp->next->next;
            else
                return NULL;
                
            if(sp==fp) {
                sp = head;
                while(sp!=fp){
                    sp = sp->next;
                    fp = fp->next;
                }
            return fp;
            }
        }
        
    }
};
