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
    bool hasCycle(ListNode *h) {
        if(!h || !h->next || !h->next->next)return false;
        
        ListNode* t = h, *f= h , *s=h;
        do{
            s = s->next;
            f=f->next->next;
        }while(s && f && f->next && (f!=s));
        return (f==s);
    }
};