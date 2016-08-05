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
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;
            
        if(!head->next)
            return true;
            
        struct ListNode* a = head;
        struct ListNode* b = head;
        struct ListNode* temp;
        struct ListNode* mid = head;
        struct ListNode* shalf = head;
        
        while(b && b->next) {
            temp = a;
            a = a->next;
            b = b->next->next;
        }

        //cout << a->val << " " << b->val << endl;
        if(b) {
            mid = a;
            a = a->next;
        }
        
        temp->next = NULL;  
        shalf = a;
        reverse(&shalf);

        while(shalf) {
            if(shalf->val != head->val) 
               return false;
               
            shalf = shalf->next;
            head = head->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode** headref) {
        ListNode* prev = NULL;
        ListNode* cur = *headref;
        ListNode* next;
        
        while(cur) {
            next = cur->next;  
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return *headref = prev;
    }
};
