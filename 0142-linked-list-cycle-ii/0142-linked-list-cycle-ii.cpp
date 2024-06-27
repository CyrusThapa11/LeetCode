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
    ListNode *detectCycle(ListNode *h) {
        if(!h || !h->next || !h->next->next)return NULL;
        ListNode*f=h,*s=h,*t,*st;
        /*         ---------             
            10 20 30 40 50 60 null           
                  s             f                               
        */
        while(f && f->next){
            f=f->next->next;
            s=s->next;
            if(f==s){                
                break;
            }
        }
        if(f!=s)return NULL;
        
        // there is prez
        s=h;
        while(s!=f){
            s=s->next;
            f=f->next;
        }
        return f;
    }
};