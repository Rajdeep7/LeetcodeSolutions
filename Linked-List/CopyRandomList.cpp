/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*,RandomListNode*> m; 
        
        RandomListNode *a = head;
        RandomListNode *b;
        
        while(a != NULL) {
            b = new RandomListNode(a->label);
            m[a] = b;
            a = a->next;
        }
        
        a = head;
        
        while(a != NULL) {
            b = m[a];
            b->next = m[a->next];
            b->random = m[a->random];
            a = a->next;
        }
        return m[head];
    }
};
