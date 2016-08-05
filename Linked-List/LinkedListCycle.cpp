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
        ListNode *sp = head;
        ListNode *fp = head;
        int flag = 0;
       
       if(head == NULL)
        return NULL;
       
        while(1) {
            if(sp->next != NULL) 
                sp = sp->next;
            else
                return false;
                
            if(fp->next!=NULL && fp->next->next!=NULL)     
                fp = fp->next->next;
            else
                return false;
                
            if(sp==fp)
                return true;
        }
    }
};
